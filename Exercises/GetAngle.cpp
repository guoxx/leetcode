#include <cstdint>

/*
* return angle in degree between [0, 360)
*/
int32_t GetAngle(int32_t degree)
{
    degree = degree % 360;
    return degree >= 0 ? : degree + 360;
}
