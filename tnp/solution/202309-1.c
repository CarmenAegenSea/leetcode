/**
 * CCF CSP 202309-1 坐标变换（其一）
 *
 * 题意：对 m 个初始点依次执行 n 个操作：
 *       操作1：平移 (dx, dy)
 *       操作2：绕原点逆时针旋转 θ 度
 *       求最终坐标。
 *
 * 算法：将所有操作合并为一个变换。
 *       平移 + 旋转可以表示为：
 *         新 x = old_x * cosθ - old_y * sinθ + dx
 *         新 y = old_x * sinθ + old_y * cosθ + dy
 *
 *       多个操作可以合并为一组 (cos, sin, dx, dy)：
 *         初始: (cos=1, sin=0, dx=0, dy=0)
 *         旋转θ: cos' = cos*cosθ - sin*sinθ, sin' = sin*cosθ + cos*sinθ
 *         平移: dx' = dx + delta_x, dy' = dy + delta_y
 *
 *   θ 是角度，需要转换为弧度。
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    double cos_sum = 1.0, sin_sum = 0.0;
    double dx_sum = 0.0, dy_sum = 0.0;

    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            /* 平移 */
            double dx, dy;
            scanf("%lf %lf", &dx, &dy);
            dx_sum += dx;
            dy_sum += dy;
        } else {
            /* 旋转 */
            double theta_deg;
            scanf("%lf", &theta_deg);
            double theta = theta_deg * PI / 180.0;
            double c = cos(theta), s = sin(theta);

            /* 旋转会同时影响之前的平移量 */
            double new_cos = cos_sum * c - sin_sum * s;
            double new_sin = sin_sum * c + cos_sum * s;
            double new_dx = dx_sum * c - dy_sum * s;
            double new_dy = dx_sum * s + dy_sum * c;

            cos_sum = new_cos;
            sin_sum = new_sin;
            dx_sum = new_dx;
            dy_sum = new_dy;
        }
    }

    for (int i = 0; i < m; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);

        double final_x = x * cos_sum - y * sin_sum + dx_sum;
        double final_y = x * sin_sum + y * cos_sum + dy_sum;

        printf("%.4f %.4f\n", final_x, final_y);
    }

    return 0;
}
