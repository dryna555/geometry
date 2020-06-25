#include "../src/foo.h"
#include "../thirdparty/ctest.h"
#include <math.h>

CTEST(colvo,v1)
{
    // Given
    char n[]="aaaa";
    int rez =0;
    // When
    int  result =isitnum(n, &rez);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(colvo,v2)
{
    // Given
    char n[]="142125wqe1.d,a";
    int rez =0;
    // When
    int  result =isitnum(n, &rez);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(colvo,v3)
{
    // Given
    char n[]="14";
    int rez =0;
    // When
    int  result =isitnum(n, &rez);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(vvodcoord,v1)
{
    // Given
    char n[]="14addsas";
    float rez =0;
    // When
    int  result =isitfl(n, &rez);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(vvodcoord,v2)
{
    // Given
    char n[]="14.14";
    float rez =0;
    // When
    int  result =isitfl(n, &rez);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(vvodcoord,v3)
{
    // Given
    char n[]="14.14.14";
    float rez =0;
    // When
    int  result =isitfl(n, &rez);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(vvodcoord,v4)
{
    // Given
    char n[]="14,14";
    float rez =0;
    // When
    int  result =isitfl(n, &rez);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(presecli,v1)
{
    // Given
    float x1 = 5;
    float x2 = 5;
    float y1 = 5;
    float y2 = 5;
    float r1 = 5;
    float r2 = 5;
    // When
    int  result = presecli(x1,y1,r1,x2,y2,r2);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(presecli,v2)
{
    // Given
    float x1 = 5;
    float x2 = 2;
    float y1 = 7;
    float y2 = 3;
    float r1 = 4;
    float r2 = 2;
    // When
    int  result = presecli(x1,y1,r1,x2,y2,r2);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(presecli,v3)
{
    // Given
    float x1 = -1;
    float x2 = 2;
    float y1 = -2;
    float y2 = 3;
    float r1 = 5;
    float r2 = 2;
    // When
    int  result = presecli(x1,y1,r1,x2,y2,r2);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(presecli,v4)
{
    // Given
    float x1 = -1;
    float x2 = 2;
    float y1 = -2;
    float y2 = 3;
    float r1 = 1;
    float r2 = 2;
    // When
    int  result = presecli(x1,y1,r1,x2,y2,r2);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
