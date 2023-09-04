#include <cstdio>
#include <cmath>
#include "egsa87.h"

// no science was involved in choosing this EPS value, it seems good enough :)
static constexpr double MY_EPS = 1e-8;

inline bool check_equal(double one, double two)
{
    return fabs( one - two) < MY_EPS;
}

    int main(int argc, char *argv[])
{
        // https://en.wikipedia.org/wiki/Morosini_Fountain
        const coords phlam{35.3391370, 25.1331727};

        coords xy = wgs84_to_egsa87(phlam);
        
        // back to WGS84
        coords phlam2 = egsa87_to_wgs84(xy);

        if (  !check_equal(phlam.phi, phlam2.phi) || !check_equal(phlam.lambda, phlam2.lambda) ) {
            printf("TEST FAILED\n");
            return EXIT_FAILURE;
        }
        printf("TEST PASSED\n");
        return EXIT_SUCCESS;
}
