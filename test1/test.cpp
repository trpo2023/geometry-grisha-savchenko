#include <../thirdparty/ctest.h>
#include <LibGeometry/func.h>

CTEST(parsing_suite, IsFingCircle)
{
    // Given
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 0;

    // When
    const int result = IsFingCircle(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

