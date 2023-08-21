
#include "management/PlotManager.h"
#include "utils/CommonValue.h"
#include "utils/Logger.h"
#include "management/ParkingLot.h"
#include "figure/Circle.h"
#include "group/Group.h"
#include "group/Car.h"
#include "group/Spacecraft.h"
#include "group/UFO.h"

#include <GL/freeglut.h>
#include <utility>
#include <iostream>

// main render function
void renderScene();

// render function only for test & debug
void renderSceneTest();

// flush background
void flushScene();

// plot parking lot
void plotParkingLot();

// ============== gate ====================
void openGate();

void closeGate();

void drawGate(float theta);

// ============== barrier ==================
void drawBarrier();

// ============== group ==================
// plot moving group animation
void moveGroup(Group *group, int slotId);

// draw group at curr position
void drawGroup(Group *group);

// rotate group
void rotateGroup(Group *group, float angle, int sign_dx, int sign_dy, bool if_flip, int cnt = 50);

// back group
void backGroup(Group *group);

// show history trajectory for group
void plotGroupHistory(Group *group, int slotId);

// convert slot id to coordination
Vec slotIdToVector(int id);




PlotManager::PlotManager(int argc, char **argv, std::string windowName, std::pair<float, float> windowSize) :
        windowName(windowName.c_str()), windowSize(windowSize), argc(argc), argv(argv) {}

PlotManager::PlotManager(int argc, char **argv) : argc(argc), argv(argv) {
    this->windowName = "p3";
    this->windowSize.first = CommonValue::DEFAULT_WINDOW_WIDTH;
    this->windowSize.second = CommonValue::DEFAULT_WINDOW_HEIGHT;
    this->windowPos = CommonValue::DEFAULT_WINDOW_POSITION;
}

int PlotManager::getSlotWidth() const {
    return slotWidth;
}


void PlotManager::setSlotWidth(int slotWidth) {
    PlotManager::slotWidth = slotWidth;
}

void PlotManager::render() {
#ifndef NO_GUI
    glutInit(&(argc), argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowSize.first, windowSize.second);
    glutInitWindowPosition(windowPos, windowPos);
    glutCreateWindow(windowName);
    glutDisplayFunc(renderScene);
    glutMainLoop();
#endif
}

void flushScene() {
#ifndef NO_GUI
    // set background color
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#endif
}

void renderScene() {
    ParkingLot &parkingLot = ParkingLot::getInstance();
    GroupManager groupManager = parkingLot.getGroupManager();
    SlotManager slotManager = parkingLot.getSlotManager();
    TicketManager ticketManager = parkingLot.getTicketManager();

    for (int i = 0; i < groupManager.getGroupNumber(); ++i) {
        flushScene();
        plotParkingLot();
        drawGate(0);
#ifndef NO_GUI
        glutSwapBuffers();
#endif
        usleep(500000);
//		Sleep(500);
        Group *group = groupManager.getGroup(i);
        int slotId = slotManager.findFirstEmptySlot(group);
//        slotId = 1;

        ticketManager.printEnterTicket(*group);
        Logger::logSlot(slotId, slotManager);
        Logger::logSeparationLine();


        if (group->getGroupType() == GroupType::IPA_TELEPORTED) {
            Vec vec = slotIdToVector(slotId);
            group->moveTo(vec);
            drawGroup(group);
        } else {
            openGate();
            moveGroup(group, slotId);
        }
        slotManager.parkGroup(group, slotId);
        parkingLot.setSlotManager(slotManager);

        if (group->getGroupType() != GroupType::IPA_TELEPORTED) {
            closeGate();
            plotGroupHistory(group, slotId);
        }
        usleep(500000);
//		Sleep(500);
    }
}

void renderSceneTest() {
    Spacecraft spacecraft;
    for (int i = 0; i < 10; ++i) {
        flushScene();
        spacecraft.zoom(i%2?2:0.5,{0,0});
        spacecraft.draw();
#ifndef NO_GUI
        glutSwapBuffers();
#endif
        sleep(1);
    }
}


void plotParkingLot() {
#ifndef NO_GUI
    // set stroke color & width
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(5);
    // 1. plot outer frame
    glBegin(GL_LINES);
    glVertex2f(-0.95, -0.95);
    glVertex2f(-0.95, 0.95);
    glVertex2f(-0.95, 0.95);
    glVertex2f(0.95, 0.95);
    glVertex2f(0.95, 0.95);
    glVertex2f(0.95, -0.75);
    glVertex2f(0.95, -0.75);
    glVertex2f(-0.65, -0.75);
    glEnd();
    // 2. plot central barrier
    drawBarrier();
    // 3. plot slots & group in slots
    // TODO: fix duplicated code
    ParkingLot &parkingLot = ParkingLot::getInstance();
    SlotManager slotManager = parkingLot.getSlotManager();
    int slotNum = slotManager.getSlotNumber();
    int num = slotNum % 2 ? (slotNum + 1) / 2 : slotNum / 2;
    float width = 0.65 * 2 / (float) num;

    glColor3f(0.2, 0.2, 0.2);
    glLineWidth(5);
    glBegin(GL_LINES);
    for (float i = 0; i <= (float) num; ++i) {
        glVertex2f(-0.65 + i * width, -0.75);
        glVertex2f(-0.65 + i * width, -0.2);
        glVertex2f(-0.65 + i * width, 0.4);
        glVertex2f(-0.65 + i * width, 0.95);
    }
    glEnd();

    for (int i = 0; i < num; ++i) {
        Group *group = nullptr;
        if ((group = slotManager.getGroup(2 * (int) i)) != nullptr) {
            group->draw();
            group->drawTrajectory(CommonValue::FORWARD_MODE, 0, 0);
        }
        if ((group = slotManager.getGroup(2 * (int) i + 1)) != nullptr) {
            group->draw();
            group->drawTrajectory(CommonValue::FORWARD_MODE, 0, 0);
        }
    }
#endif
}

void drawBarrier() {
#ifndef NO_GUI
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.675, 0.13);
    glVertex2f(-0.675 + 0.025, 0.1);
    glVertex2f(-0.675, 0.07);
    glEnd();
    for (int i = 0; i < 26; ++i) {
        (!(i % 2)) ? glColor3f(0.9, 0.8, 0.1) : glColor3f(0, 0, 0);
        glLineWidth(50);
        glBegin(GL_POLYGON);
        glVertex2f(-0.675 + 0.05 * i, 0.13);
        glVertex2f(-0.675 + 0.05 * (i + 1), 0.13);
        glVertex2f(-0.675 + 0.05 * (i + 1) + 0.025, 0.1);
        glVertex2f(-0.675 + 0.05 * i + 0.025, 0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.675 + 0.05 * i + 0.025, 0.1);
        glVertex2f(-0.675 + 0.05 * (i + 1) + 0.025, 0.1);
        glVertex2f(-0.675 + 0.05 * (i + 1), 0.07);
        glVertex2f(-0.675 + 0.05 * i, 0.07);
        glEnd();
    }
    glColor3f(0.9, 0.8, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.625, 0.13);
    glVertex2f(0.675, 0.13);
    glVertex2f(0.675, 0.1);
    glVertex2f(0.65, 0.1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.65, 0.1);
    glVertex2f(0.675, 0.1);
    glVertex2f(0.675, 0.07);
    glVertex2f(0.625, 0.07);
    glEnd();
#endif
}

void drawGate(float theta) {
#ifndef NO_GUI
    // draw pole
    if (abs(theta - M_PI_2) < 1e-5) {
        glColor3f(0.1, 0.9, 0);
    } else if (abs(theta) < 1e-5) {
        glColor3f(1, 0, 0);
    } else {
        glColor3f(1, 0.9, 0.1);
    }
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-0.65, -0.75);
    glVertex2f(-0.65 + 0.25 * cos(M_PI + theta), -0.75 + 0.25 * sin(M_PI + theta));
    glEnd();
    // draw pivot
    Circle pivot({-0.65, -0.75}, 0.015, {0.7, 0.7, 0.7});
    pivot.draw();
#endif
}

void openGate() {
    for (int i = 0; i <= 100; ++i) {
        flushScene();
        plotParkingLot();
        drawGate(M_PI_2 / 100 * i);
        usleep(20000);
//		Sleep(200);
#ifndef NO_GUI
        glutSwapBuffers();
#endif
    }
}

void closeGate() {
    for (int i = 100; i >= 0; --i) {
        flushScene();
        plotParkingLot();
        drawGate(M_PI_2 / 100 * i);
        usleep(20000);
//		Sleep(200);
#ifndef NO_GUI
        glutSwapBuffers();
#endif
    }
}

void moveGroup(Group *group, int slotId) {
    ParkingLot &parkingLot = ParkingLot::getInstance();
    int slotNum = parkingLot.getSlotManager().getSlotNumber();
    int num = slotNum % 2 ? (slotNum + 1) / 2 : slotNum / 2;
    float width = 0.65 * 2 / (float) num;

    if (group->getGroupType() == GroupType::IPA_CAR) {
        group->rotate(M_PI_2);
    }
    group->moveTo({-0.7, -0.65}); // move to start point
    group->move(group->getAdjustParam()); // self-adjust
    drawGroup(group); // initial plotting

    // 1. move vertically
    for (int i = 0; i < 53; ++i) {
        group->move({0, CommonValue::DELTA_DIS});
        drawGroup(group);
    }
    rotateGroup(group, -M_PI_2, 1, -1, false);
    // 2. move horizontally
    int dx = slotId % 2 ? slotNum / 2 : slotId / 2;
    float dis = (slotId % 2 ? dx : (dx - 0.5)) * width + (slotId % 2 ? 0.2 : 0.22);
    dx = (int) (dis / CommonValue::DELTA_DIS) - (slotId % 2 ? group->getStepAddition() : 0);
    for (int i = 0; i < dx + group->getStepAddition(); ++i) {
        group->move({CommonValue::DELTA_DIS, 0});
        drawGroup(group);
    }
    // 3.
    if (slotId % 2 == 0) {
        rotateGroup(group, -M_PI_2, -1, -1, true);
        for (int i = 0; i < 35; ++i) {
            group->move({0, -CommonValue::DELTA_DIS});
            drawGroup(group);
        }
    } else {
        dx = slotNum / 2 - (slotId + 1) / 2 + 1;
        dx = (int) (((dx + 0.5) * width + 0.065) / CommonValue::DELTA_DIS);
        rotateGroup(group, M_PI_2, 1, -1, true);
        for (int i = 0; i < 24; ++i) {
            group->move({0, CommonValue::DELTA_DIS});
            drawGroup(group);
        }
        rotateGroup(group, M_PI_2, -1, -1, false);
        for (int i = 0; i < dx; ++i) {
            group->move({-CommonValue::DELTA_DIS, 0});
            drawGroup(group);
        }
        for (int i = 0; i < 15; ++i) {
            drawGroup(group);
            usleep(20000);
//			Sleep(200);
		}
        backGroup(group);
    }
}

void drawGroup(Group *group) {
#ifndef NO_GUI
    flushScene();
    plotParkingLot();
    drawGate(M_PI_2);
    group->drawTrajectory(CommonValue::FORWARD_MODE, 0, CommonValue::TRAJECTORY_POINTS_NUM);
    group->draw();
    glutSwapBuffers();
    usleep(50000);
//	Sleep(50);
#endif
}

void rotateGroup(Group *group, float angle, int sign_dx, int sign_dy, bool if_flip, int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        group->rotate(angle / (float) cnt);
        float theta = abs(angle) / (float) cnt * (float) i;
        float theta_ = abs(angle) / (float) cnt * (float) (i - 1);
        float dx = CommonValue::DELTA_DIS * 5 * (cos(theta_) - cos(theta)) * sign_dx;
        float dy = CommonValue::DELTA_DIS * 5 * (sin(theta_) - sin(theta)) * sign_dy;
        (!if_flip) ? group->move({dx, dy}) : group->move({dy, dx});
        drawGroup(group);
    }
}

void backGroup(Group *group) {
    for (int i = 1; i <= 100; ++i) {
        group->rotate(M_PI_2 / 100);
        float theta = M_PI_2 / 100 * i;
        float theta_ = M_PI_2 / 100 * (i + 1);
        float dx = abs(sin(theta) - sin(theta_)) * 0.2;
        float dy = abs(cos(theta) - cos(theta_)) * 0.2;
        group->move({dx, dy});
#ifndef NO_GUI
        flushScene();
        plotParkingLot();
        drawGate(M_PI_2);
        group->drawTrajectory(CommonValue::BACK_MODE, theta, 10);
        group->draw();
        glutSwapBuffers();
		//Sleep(60);
        usleep(60000);
#endif
    }
    for (int i = 0; i < 30; ++i) {
        group->move({0, CommonValue::DELTA_DIS});
#ifndef NO_GUI
        flushScene();
        plotParkingLot();
        drawGate(M_PI_2);
        group->drawTrajectory(CommonValue::BACK_MODE, M_PI_2, 10 * (30 - i - 1) / 30);
        group->draw();
        glutSwapBuffers();
        usleep(50000 + 30000 / 30 * (i + 1));
//		Sleep(500 + 300 / 30 * (i + 1));
#endif
    }
}

void plotGroupHistory(Group *group, int slotId) {
    if (group->getGroupType() != GroupType::IPA_TELEPORTED) {
#ifndef NO_GUI
        flushScene();
        plotParkingLot();
        drawGate(0);
        // plot history trajectory
        Trajectory *trajectory = group->getTrajectory();
        trajectory->plotHistory(slotId % 2 ? CommonValue::UP : CommonValue::DOWN);
        glutSwapBuffers();
#endif
    }
}

Vec slotIdToVector(int id) {
    // TODO: fix duplicated code
    ParkingLot &parkingLot = ParkingLot::getInstance();
    SlotManager slotManager = parkingLot.getSlotManager();
    int slotNum = slotManager.getSlotNumber();
    int num = slotNum % 2 ? (slotNum + 1) / 2 : slotNum / 2;
    float width = 0.65 * 2 / (float) num;

    return {static_cast<float>(-0.65 + width * (ceil((double) (id + 1) / 2) - 0.5)),
            static_cast<float>((id) % 2 ? 0.7 : -0.5)};
}


