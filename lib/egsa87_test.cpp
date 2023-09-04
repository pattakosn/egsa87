#include <cstdio>
#include <cmath>
#include "egsa87.h"

static constexpr double MY_EPS = 1e-8;

inline bool check_equal(double one, double two)
{
    return fabs( one - two) < MY_EPS;
}

    int main(int argc, char *argv[])
{
        // https://en.wikipedia.org/wiki/Morosini_Fountain
        const coords phlam{35.3391370 * M_PI/180.0, 25.1331727 * M_PI/180.0};

        coords xy = wgs84egsa87(phlam);
        //printf("Point in EGSA87: %lf %lf\n", xy[0], xy[1]);
        
        // back to WGS84
        coords phlam2 = egsa87wgs84(xy);
        //phlam2[0] *= 180.0/M_PI;
        //phlam2[1] *= 180.0/M_PI;
        //printf("Point in WGS84: %lf %lf\n", phlam2[0], phlam2[1]);

        if (  !check_equal(phlam.phi, phlam2.phi) || !check_equal(phlam.lambda, phlam2.lambda) ) {
            printf("TEST FAILED\n");
            return EXIT_FAILURE;
        }
        printf("TEST PASSED\n");
        return EXIT_SUCCESS;
}
