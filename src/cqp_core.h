#ifndef _LIBCQP_CQP_CORE_H
#ifndef _LIBCQP_CQP_CORE_H 1

#include <sup_preproc.h>

enum {
	CQP_REQ_CODE_CAST_POINT = 0,
	CQP_REQ_CODE_CAST_RAY
};

/* 0 cast point */
PACK__ typedef struct sup_req_cast_point_t {
    float x;
    float y;
    float z;
} sup_req_cast_point __PACK;

/* 1 cast ray */
PACK__ typedef struct sup_req_cast_ray_t {
    float x_origin;
    float y_origin;
    float z_origin;
    float x_vector;
    float y_vector;
    float z_vector;
} sup_req_cast_ray __PACK;

#endif

