#ifndef __SHARE_MACROS_H_
#define __SHARE_MACROS_H_

#define EMPTY_POINT( p ) ( ( p.x == 0 && p.y == 0 ) ? true : false )
#define NOT_EMPTY_POINT( p ) ( ( p.x != 0 || p.y != 0 ) ? true : false )
#define NOT_EMPTY( x ) ( x != 0 ? true : false )

#endif // SHARE_MACROS_H_