// license:GPL-2.0+
// copyright-holders:Couriersud
/*
 * vector_base.h
 *
 * Base vector operations
 *
 */

#ifndef VECTOR_BASE_H_
#define VECTOR_BASE_H_

#include <algorithm>
#include "../plib/pconfig.h"

#if 0
template <unsigned _storage_N>
struct pvector
{
	pvector(unsigned size)
	: m_N(size) { }

	unsigned size() {
		if (_storage_N)
	}

	double m_V[_storage_N];
private:
	unsigned m_N;
};
#endif

#if !defined(__clang__) && !defined(_MSC_VER)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

inline void vec_set (const std::size_t n, const double &scalar, double * RESTRICT result)
{
	for ( std::size_t i = 0; i < n; i++ )
		result[i] = scalar;
}
inline double vecmult (const std::size_t n, const double * RESTRICT a1, const double * RESTRICT a2 )
{

	double value = 0.0;
	for ( std::size_t i = 0; i < n; i++ )
		value = value + a1[i] * a2[i];
	return value;
}


inline double vecmult2 (const std::size_t n, const double *a1)
{
	double value = 0.0;
	for ( std::size_t i = 0; i < n; i++ )
	{
		const double temp = a1[i];
		value = value + temp * temp;
	}
	return value;
}

inline void vec_mult_scalar (const std::size_t n, const double * RESTRICT v, const double scalar, double * RESTRICT result)
{
	for ( std::size_t i = 0; i < n; i++ )
	{
		result[i] = scalar * v[i];
	}
}

inline void vec_add_mult_scalar (const std::size_t n, const double * RESTRICT v, const double scalar, double * RESTRICT result)
{
	for ( std::size_t i = 0; i < n; i++ )
		result[i] += scalar * v[i];
}

inline void vec_add_ip(const std::size_t n, const double * RESTRICT v, double * RESTRICT result)
{
	for ( std::size_t i = 0; i < n; i++ )
		result[i] += v[i];
}

inline void vec_sub(const std::size_t n, const double * RESTRICT v1, const double * RESTRICT v2, double * RESTRICT result)
{
	for ( std::size_t i = 0; i < n; i++ )
		result[i] = v1[i] - v2[i];
}

inline void vec_scale (const std::size_t n, double * RESTRICT v, const double scalar)
{
	for ( std::size_t i = 0; i < n; i++ )
		v[i] = scalar * v[i];
}

inline double vec_maxabs(const std::size_t n, const double * RESTRICT v)
{
	double ret = 0.0;
	for ( std::size_t i = 0; i < n; i++ )
		ret = std::max(ret, std::abs(v[i]));

	return ret;
}
#if !defined(__clang__) && !defined(_MSC_VER)
#pragma GCC diagnostic pop
#endif

#endif /* MAT_CR_H_ */
