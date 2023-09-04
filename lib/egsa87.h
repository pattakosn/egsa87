#ifndef _EGSA87_H
#define _EGSA87_H

struct coords {
	double phi;
	double lambda;
};
coords wgs84egsa87(const coords in_radians);//double philam[2]);
coords egsa87wgs84(const coords in_EGSA87_meters);//double xy[2]);

#endif

