/** ******************************************************
 * Diseño y analisis de algoritmos                       *
 * El problema de corte bidimensional sin restricciones  *
 * es el problema de cortar de una lamina plana          *
 * rectangular un conjunto de piezas rectangulares más   *
 * pequeñas, de un tamaño dado, y cada una con un valor, * 
 * de manera que se maximice el valor de las piezas      *
 * a cortar.                                             *
 *                                                       *
 * @author Juan Francisco González Ramos                 * 
 * @version 0.2                                          *
 * @copyright Creative Commons
 * *******************************************************/

#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include"../cortes.h"

using namespace CppUnit;
using namespace std;

//-------------

class UnitTestCase : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(UnitTestCase);
    CPPUNIT_TEST(test);
    CPPUNIT_TEST_SUITE_END();
 
public:
    void setUp(void);
    void tearDown(void);

protected:
    void test(void);
private:
    
	CCortes* cCortes;
};