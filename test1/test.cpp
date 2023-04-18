#include <ctest.h>
#include <func.h>

// Given
const std::string str = "circle(2 2, 3.1)";
const std::string er1 = "circe(2 2, 3.1)";
const std::string er2 = "circle)2 2, 3.1)";
std ::string point1 = "";

CTEST(parsing_suite, IsFingCircle)
{
    unsigned int i = 0;
    // When
    const int result = IsFingCircle(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error1)
{
    unsigned int i = 0;
    // When
    const int result = IsFingCircle(er1, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftBracket)
{
    unsigned int i = 6;
    // When
    const int result = IsFingLeftBracket(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error2)
{
    unsigned int i = 6;
    // When
    const int result = IsFingLeftBracket(er2, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingFirstDigit1)
{
    unsigned int i = 7;
    // When
    const int result = IsFingFirstDigit1(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er3 = "circle(f 2, 3.1)";

CTEST(parsing_suite, error3)
{
    unsigned int i = 7;
    // When
    const int result = IsFingFirstDigit1(er3, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingSecDigit2)
{
    unsigned int i = 9;
    // When
    const int result = IsFingSecDigit2(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er4 = "circle(2 f, 3.1)";

CTEST(parsing_suite, error4)
{
    unsigned int i = 9;
    // When
    const int result = IsFingFirstDigit1(er4, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftComma)
{
    unsigned int i = 10;
    // When
    const int result = IsFingLeftComma(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er5 = "circle(2 2. 3.1)";

CTEST(parsing_suite, error5)
{
    unsigned int i = 10;
    // When
    const int result = IsFingLeftComma(er5, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftDigit3)
{
    unsigned int i = 12;
    // When
    const int result = IsFingLeftDigit3(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er6 = "circle(2 2, 3g1)";

CTEST(parsing_suite, error6)
{
    unsigned int i = 12;
    // When
    const int result = IsFingLeftDigit3(er6, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingRightBracket)
{
    unsigned int i = 15;
    // When
    const int result = IsFingRightBracket(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er7 = "circle(2 2, 3.1(";

CTEST(parsing_suite, error7)
{
    unsigned int i = 15;
    // When
    const int result = IsFingRightBracket(er7, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, UnexToken)
{
    unsigned int i = 16;
    // When
    const int result = UnexToken(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er8 = "circle(2 2, 3.1) o";

CTEST(parsing_suite, error8)
{
    unsigned int i = 16;
    // When
    const int result = UnexToken(er8, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

// ASSERT_DBL_NEAR(exp, real)

CTEST(math_suit, perimter)
{
    // then
    const double r = 1;
    // When
    const double result = perimter(r);

    // Then
    const double expected = 2 * r * 3.14;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(math_suit, area)
{
    // then
    const double r = 1;
    // When
    const double result = area(r);

    // Then
    const double expected = r * r * 3.14;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(math_suit, intersect)
{
    // then
    const int k = 2;
    double** prmtrs;
    prmtrs = new double*[k];
    for (int i = 0; i < k; i++)
        prmtrs[i] = new double[3];
    prmtrs[0][0] = 2;
    prmtrs[0][1] = 2;
    prmtrs[0][2] = 3.1;
    prmtrs[1][0] = 1;
    prmtrs[1][1] = 1;
    prmtrs[1][2] = 10;

    // When
    const int result = intersect(prmtrs, 0, 1);

    // Then
    const double expected = 1;
    for (int i = 0; i < k; i++) {
        delete prmtrs[i];
    }
    delete prmtrs;
    ASSERT_EQUAL(expected, result);
}

CTEST(math_suit, Not_intersect)
{
    // then
    const int k = 2;
    double** prmtrs;
    prmtrs = new double*[k];
    for (int i = 0; i < k; i++)
        prmtrs[i] = new double[3];
    prmtrs[0][0] = 100;
    prmtrs[0][1] = 100;
    prmtrs[0][2] = 1;
    prmtrs[1][0] = 1;
    prmtrs[1][1] = 1;
    prmtrs[1][2] = 1;

    // When
    const int result = intersect(prmtrs, 0, 1);

    // Then
    const double expected = 0;
    for (int i = 0; i < k; i++) {
        delete prmtrs[i];
    }
    delete prmtrs;
    ASSERT_EQUAL(expected, result);
}
