

#ifndef P3_COMMONVALUE_H
#define P3_COMMONVALUE_H

#include <cmath>

class CommonValue {
public:
    // ============== Mode ====================
    static const int PMS_MODE = 1;
    static const int IPA_MODE = 2;
    // ============== Group ====================
    static const int MAX_GROUP_SIZE = 10;
    static const int MIN_GROUP_SIZE = 1;
    // =============== PMS ========================
    static const int PMS_TYPE_MAX = 4;
    static const int MAX_DURATION = 100;
    static const int MAX_SLOT_NUM = 10000;
    // =============== WINDOW =======================
    static const int DEFAULT_WINDOW_WIDTH = 400;
    static const int DEFAULT_WINDOW_HEIGHT = 400;
    static const int DEFAULT_WINDOW_POSITION = 100;
    // =============== PLOT =========================
    constexpr static const float DELTA_DIS = 0.01f;
    static const int TRAJECTORY_POINTS_NUM = 25;
    constexpr static const float TRAJECTORY_MAX_WIDTH = 10;
    // =============== IPA =========================
    static const int IPA_TYPE_MIN = 5;
    static const int IPA_TYPE_MAX = 8;
    static const int FORWARD_MODE = 1;
    static const int BACK_MODE = 2;
    static const int ROTATE_MODE = 3;
    constexpr static const float UFO_ROTATION_DEGREE = M_PI_2 / 10;
    constexpr static const float SPACECRAFT_SCALE_MIN = 0.8;
    constexpr static const float SPACECRAFT_SCALE_MAX = 1.2;
    // =============== Direction ==================
    static const int UP = 1;
    static const int RIGHT = 2;
    static const int DOWN = 3;
    static const int LEFT = 4;
};

#endif //P3_COMMONVALUE_H
