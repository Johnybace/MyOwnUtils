#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "airclass.h"
#include "cinclearbuffer.cpp"
#include "welcome.h"
#include "selectfunction.h"
#include "ticTacToe.h"


SelectFunction::SelectFunction()
{
	static bool isPrintet{ false };

	double dumyForTubeAva{}, dumyForTubeAvb{};

	std::string dumyForWhat {};

	static std::string project {};

	static std::vector <TubeProtocol> objectCollectionTubePr {};
	static std::vector <DuctProtocol> objectCollectionDuctPr {};
	static std::vector <VAVProtocol> objectCollectionVAVPr {};
	static std::vector <ExpSpeedAvInTubes> objectCollectionTubeAv {};
	static std::vector <ExpSpeedAvInDucts> objectCollectionDuctAv {};

	Welcome();

		do
		{
			AirVolMenu();

			std::cout << std::setw(31) << insertFunction;
			Form = readValue<int>();
			if( Form < 0 || Form > 20 )
			{
				ClearScreen();
				Welcome();
				std::cout << std::endl << std::endl << std::setw(60) << warning << std::endl << std::endl;
			}

		} while( Form < 0 || Form >20 );

	TubeProtocol TubePr;
	DuctProtocol DuctPr;
	VAVProtocol VAVPr;
	ExpSpeedAvInTubes TubeAv;
	ExpSpeedAvInDucts DuctAv;
	TicTacToe game;
	
	switch( Form )
	{
	case 0:
		Goodbey();
		break;

	case 1:
		if ( project.empty() )
		{
			std::cout << std::endl << std::setw(31) << printIinsertProjectName;
			std::getline( std::cin, project );
		}
			TubePr.setMeasurementPoint( dumyForWhat );
			TubePr.setDiameter( dumyForTubeAva );
			TubePr.setCalcCircularArea( dumyForTubeAva );
			TubePr.setSetPointAirVolume( dumyForTubeAvb );
		do 
		{
			TubePr.setMeasuredSpeed( dumyForTubeAva );
			TubePr.setV_Max( dumyForTubeAva );
			TubePr.setV_Min( dumyForTubeAva );
			TubePr.setV_Sum( dumyForTubeAva );
			TubePr.setCounterSpeedIn( dumyForTubeAva );
			loop = readValue<char>();
		}while( loop != doloop );
			TubePr.setCalcSpeedAvInTubes( dumyForTubeAvb, dumyForTubeAva );
			TubePr.setAverageSpeed( dumyForTubeAva );
			TubePr.setAirvolume( dumyForTubeAva );
			TubePr.setDeviation( dumyForTubeAva );
			objectCollectionTubePr.emplace_back( TubePr );
			std::cout << std::endl;
			std::cout << TubePr << std::endl;
			std::cin.get();
		ClearScreen();
		SelectFunction();
		break;
	
	case 2:
		if( project.empty() )
		{
			std::cout << std::endl << std::setw(31) << printIinsertProjectName;
			std::getline( std::cin, project );
		}
			DuctPr.setMeasurementPoint( dumyForWhat);
			DuctPr.setWidth( dumyForTubeAva );
			DuctPr.setHeight( dumyForTubeAvb );
			DuctPr.setCalcOrthogonArea( dumyForTubeAva, dumyForTubeAvb );
			DuctPr.setSetPointAirVolume( dumyForTubeAva );
		do 
		{
			DuctPr.setMeasuredSpeed( dumyForTubeAva );
			DuctPr.setV_Max( dumyForTubeAva );
			DuctPr.setV_Min( dumyForTubeAva );
			DuctPr.setV_Sum( dumyForTubeAva );
			DuctPr.setCounterSpeedIn( dumyForTubeAva );															
			loop = readValue<char>();
		}while( loop != doloop );
			DuctPr.setCalcSpeedAvInDucts( dumyForTubeAvb, dumyForTubeAva );
			DuctPr.setAverageSpeed( dumyForTubeAva );
			DuctPr.setAirvolume(dumyForTubeAva);
			DuctPr.setDeviation(dumyForTubeAva);
			objectCollectionDuctPr.emplace_back( DuctPr );
			std::cout << std::endl;
			std::cout << DuctPr << std::endl;
			std::cin.get();
		ClearScreen();
		SelectFunction();
		break;

	case 3:
		if( project.empty() )
		{
			std::cout << std::endl << std::setw(31) << printIinsertProjectName;
			std::getline( std::cin, project );
		}
			VAVPr.setMeasurementPoint( dumyForWhat );
			VAVPr.setSetPointAirVolume( dumyForTubeAva );
			VAVPr.setV_Nom( dumyForTubeAva );
			VAVPr.setV_Max( dumyForTubeAva );
			VAVPr.setV_Min( dumyForTubeAva );
			VAVPr.setDeputySignal( dumyForWhat );
			VAVPr.setSpinDirection( dumyForWhat );
			VAVPr.setMaxAirvolume( dumyForTubeAva );
			VAVPr.setMinAirvolume( dumyForTubeAva );
			VAVPr.setDeviation( dumyForTubeAva );
			objectCollectionVAVPr.emplace_back( VAVPr );
			std::cout << std::endl;
			std::cout << VAVPr << std::endl;
			std::cin.get();
		ClearScreen();
		SelectFunction();
		break;

	case 4:
		TubeAv.setDiameter( dumyForTubeAva );
		TubeAv.setCalcCircularArea( dumyForTubeAva );
		TubeAv.setSetPointAirVolume( dumyForTubeAvb );
		TubeAv.setCalcSpeedAvInTubes( dumyForTubeAvb, dumyForTubeAva );
		objectCollectionTubeAv.emplace_back( TubeAv );
		std::cout << TubeAv << std::endl;
		std::cin.get();
		ClearScreen();
		SelectFunction();
		break;
		
	case 5:
		DuctAv.setWidth( dumyForTubeAva );
		DuctAv.setHeight( dumyForTubeAvb );
		DuctAv.setCalcOrthogonArea( dumyForTubeAva, dumyForTubeAvb );
		DuctAv.setSetPointAirVolume( dumyForTubeAva );
		DuctAv.setCalcSpeedAvInDucts( dumyForTubeAvb, dumyForTubeAva );
		objectCollectionDuctAv.emplace_back( DuctAv );
		std::cout << DuctAv << std::endl;
		std::cin.get();
		ClearScreen();
		SelectFunction();
		break;

	case 6:
		VentilatorPressure();
		std::cin.get();
		ClearScreen();
		SelectFunction();
		break;

	case 7:
		if( !objectCollectionTubeAv.empty() )
		{
			std::cout << std::endl << std::setw(21) << printPipes << std::endl << std::endl;
			std::for_each( objectCollectionTubeAv.begin(),
						   objectCollectionTubeAv.end(),
						   []( ExpSpeedAvInTubes &objectCollection )
							{
						   		std::cout << objectCollection << std::endl;
							} );
		}
		if( !objectCollectionDuctAv.empty() )
		{
			std::cout << std::endl << std::setw(21) << printDucts << std::endl << std::endl;
			std::for_each( objectCollectionDuctAv.begin(),
						   objectCollectionDuctAv.end(),
						   []( ExpSpeedAvInDucts &objectCollection )
							{
						        std::cout << objectCollection << std::endl;
							} );
		}
		if( !project.empty() )
		{
			std::cout << std::endl << std::setw(26) << printProject << std::setw(1) << " " << std::setw(1) << project << std::endl << std::endl;
		}
		if( !objectCollectionTubePr.empty() )
		{
			std::for_each( objectCollectionTubePr.begin(),
						   objectCollectionTubePr.end(),
						   []( TubeProtocol &objectCollection )
							{
								std::cout << objectCollection << std::endl;
							} );
		}
		if( !objectCollectionDuctPr.empty() )
		{
			std::for_each( objectCollectionDuctPr.begin(),
						   objectCollectionDuctPr.end(),
						   []( DuctProtocol &objectCollection )
							{
								std::cout << objectCollection << std::endl;
							} );
		}
		if( !objectCollectionVAVPr.empty() )
		{
			std::for_each( objectCollectionVAVPr.begin(),
						   objectCollectionVAVPr.end(),
						   []( VAVProtocol &objectCollection )
							{
								std::cout << objectCollection << std::endl;
							} );
		}
		std::cin.get();
		ClearScreen();
		SelectFunction();
		break;

	case 8:
		Dummy8();
		ClearScreen();
		SelectFunction();
		break;

	case 9:
		Dummy9();
		ClearScreen();
		SelectFunction();
		break;

	case 10:
		Dummy10();
		ClearScreen();
		SelectFunction();
		break;

	case 11:
		Dummy11();
		ClearScreen();
		SelectFunction();
		break;

	case 12:
		Dummy12();
		ClearScreen();
		SelectFunction();
		break;

	case 13:
		Dummy13();
		ClearScreen();
		SelectFunction();
		break;

	case 14:
		Dummy14();
		ClearScreen();
		SelectFunction();
		break;

	case 15:
		Dummy15();
		ClearScreen();
		SelectFunction();
		break;

	case 16:
		Dummy16();
		ClearScreen();
		SelectFunction();
		break;

	case 17:
		Dummy17();
		ClearScreen();
		SelectFunction();
		break;

	case 18:
		Dummy18();
		ClearScreen();
		SelectFunction();
		break;

	case 19:
		Dummy19();
		ClearScreen();
		SelectFunction();
		break;

	case 20:
		char playerOnMove {'X'};
		do
		{
			game.player;
			if( game.player == 2 )game.computerLogic( game.player );
			if( game.player == 1 )game.startGame( playerOnMove );

		}while( game.field01 == true || 
	    		game.field02 == true ||
	    		game.field03 == true ||
	    		game.field04 == true ||
	    		game.field05 == true ||
	    		game.field06 == true ||
	    		game.field07 == true ||
	    		game.field08 == true ||
	    		game.field09 == true );
		game.gameOver();
		std::cin.get();
		ClearScreen();
		SelectFunction();
		break;
	}
}

SelectFunction::~SelectFunction()
{
}