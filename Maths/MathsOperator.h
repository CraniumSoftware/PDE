// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef MATHS_OPERATOR_H
#define MATHS_OPERATOR_H

#define COMMUTATIVE_PRE_OPERATOR( PreType, PostType, op ) \
friend inline PostType operator op( const PreType& x, const PostType& y ) \
{ \
    return y op x; \
}

#define ANTI_COMMUTATIVE_PRE_OPERATOR( PreType, PostType, op ) \
friend inline PostType operator op( const PreType& x, const PostType& y ) \
{ \
    return -y op x; \
}

#define VECTOR_COMPONENT_WISE_UNARY_OPERATOR( VectorBase, BaseType, op ) \
inline VectorBase& operator op( const BaseType& _x ) \
{ \
    for( int i = 0; i < iComponentCount; ++i ) \
    { \
        maComponents[ i ] op _x; \
    } \
\
    return *this; \
} \
\
inline VectorBase& operator op( const VectorBase& _x ) \
{ \
    for( int i = 0; i < iComponentCount; ++i ) \
    { \
        maComponents[ i ] op _x[ i ]; \
    } \
\
    return *this; \
}

#define VECTOR_COMPONENT_WISE_BINARY_OPERATOR_FROM_UNARY( VectorBase, BaseType, op, opE ) \
template< class T > inline VectorBase operator op( const T& _x ) const \
{ \
    VectorBase v( *this ); \
    v opE _x; \
    return v; \
}

#define USE_BASE_OPERATORS( Base ) \
	using Base::operator =; \
	using Base::operator +; \
	using Base::operator -; \
	using Base::operator *; \
	using Base::operator /; \
	using Base::operator +=; \
	using Base::operator -=; \
	using Base::operator *=; \
	using Base::operator /=; \

#endif
