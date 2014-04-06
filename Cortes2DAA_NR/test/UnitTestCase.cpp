#include"UnitTestCase.h"


//-----------------------------------------------------------------------------

void UnitTestCase::test(void)
{
  
  ifstream fich ("../prueba1.cg");
  CCortes cortes (10, 10, fich);
  fich.close ();
  cortes.cortes (10, 10);
 
  

        CPPUNIT_ASSERT( cortes.getPos (10, 10)== 80);
}

 
void UnitTestCase::setUp(void)

{
}


void UnitTestCase::tearDown(void)

{
  delete cCortes;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( UnitTestCase );

int main(int argc, char* argv[])
{
  CPPUNIT_NS::TestResult testresult;
    // register listener for collecting the test-results

    CPPUNIT_NS::TestResultCollector collectedresults;

    testresult.addListener (&collectedresults);


    // register listener for per-test progress output

    CPPUNIT_NS::BriefTestProgressListener progress;

    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());

    testrunner.run(testresult);

 
    // output results in compiler-format

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);

    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin

    ofstream xmlFileOut("cppUnitTest.xml");

    XmlOutputter xmlOut(&collectedresults, xmlFileOut);

    xmlOut.write();

    // return 0 if tests were successful

    return collectedresults.wasSuccessful() ? 0 : 1;



}
