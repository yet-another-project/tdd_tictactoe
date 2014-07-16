#ifndef TESTUNIT_H
#define TESTUNIT_H

#define test_assert(message, test) do { if (!(test)) return message; } while (0)
#define run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)
extern int tests_run;

#endif
