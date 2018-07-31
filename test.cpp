#include "API_Ability_Unit.hpp"
#include "API_Fight.hpp"
#include "API_Magic_Unit.hpp"
#include "API_Unit.hpp"

#include "IMP_Factory.hpp"

#include "Spell.hpp"

#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include <iostream>

typedef
std::vector< std::unique_ptr< GameModel::Unit > >
ArmyContainer;


GameModel::Implementation::fightContainer prepareRedArmy( ArmyContainer & _army )
{
	using namespace GameModel;

	Implementation::GameFactory factory;

	Implementation::fightContainer container;

	int cannonFodderCount = 50;

	for ( int i = 0 ; i < cannonFodderCount; ++i )
	{
		std::unique_ptr< GameModel::Unit > unit =  factory.createUnit( 15, 6, 0 );
		container.push_back( unit.get() );
		_army.push_back( std::move( unit ) );
	}

	return container;
}


GameModel::Implementation::fightContainer prepareBlueArmy( ArmyContainer & _army )
{
	using namespace GameModel;

	Implementation::GameFactory factory;

	Implementation::fightContainer container;

	int eliteTroopsCount = 15;

	for ( int i = 0 ; i < eliteTroopsCount; ++i )
	{
		std::unique_ptr< GameModel::Unit > unit =  factory.createUnit( 50, 7, 0 );
		container.push_back( unit.get() );
		_army.push_back( std::move( unit ) );
	}

	return container;
}

enum BattleState{ InProcess, BlueWon, RedWon };

BattleState isBattleOver(
		GameModel::Implementation::fightContainer& _red
	,	GameModel::Implementation::fightContainer& _blue
)
{
	bool armyDestroyed = true;

	for( auto& unit : _red )
	{
		if( unit->getCurentHP() != 0 )
		{
			armyDestroyed = false;
			break;
		}
	}

	if( armyDestroyed )
	{
		return BlueWon;
	}

	armyDestroyed = true;

	for( auto& unit : _blue )
	{
		if( unit->getCurentHP() != 0 )
		{
			armyDestroyed = false;
			break;
		}
	}

	return armyDestroyed ? RedWon : InProcess;

}

void simulateFight(
		GameModel::Fight & _fight
	,	GameModel::Implementation::fightContainer& _red
	,	GameModel::Implementation::fightContainer& _blue
)
{
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "                The battle has begun!" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;

	srand( time( NULL ) );

	BattleState state = InProcess;

	int roundNo = 1;

	while( state == InProcess )
	{
		int redSoldierNo = rand() % _red.size();

		while( ( _red.at( redSoldierNo )->getCurentHP() ) == 0 )
		{
			redSoldierNo = ( redSoldierNo == _red.size() - 1 ) ? 0 : redSoldierNo + 1;
		}

		int blueSoldierNo = rand() % _blue.size();

		while( ( _blue.at( blueSoldierNo )->getCurentHP() ) == 0 )
		{
			blueSoldierNo = ( blueSoldierNo == _blue.size() - 1 ) ? 0 : blueSoldierNo + 1;
		}

		GameModel::Unit & redArmySoldier = *_red.at( redSoldierNo );
		GameModel::Unit & blueArmySoldier = *_blue.at( rand() % _blue.size() );

		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "Round #" << roundNo << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;

		std::cout
			<< "Trying to fight with Red#"
			<< redSoldierNo + 1
			<< " and blue #"
			<< blueSoldierNo + 1
			<< std::endl
		;

		if( ( redArmySoldier.getCurentHP() == 0 ) ||  ( blueArmySoldier.getCurentHP() == 0 ) )
		{
			std::cout << "Round cannot proceed: some of units are deceased." << std::endl;
			continue;
		}

		std::cout
			<< "Red unit HP before action:"
			<< redArmySoldier.getCurentHP()
			<<"; Blue unit HP before action:"
			<< blueArmySoldier.getCurentHP()
			<< std::endl
		;

		_fight.doubleHit( blueArmySoldier, redArmySoldier );

		std::cout
			<< "Red unit HP after action:"
			<< redArmySoldier.getCurentHP()
			<<"; Blue unit HP after action:"
			<< blueArmySoldier.getCurentHP()
			<< std::endl
		;

		std::cout << "--------------------------------------------------------------" << std::endl;

		state = isBattleOver( _red, _blue );
		++roundNo;
	}

	std::cout << "--------------------------------------------------------------" << std::endl;

	std::cout << ( ( state == RedWon ) ? "Red" : "Blue" ) << " won the battle." << std::endl;

	std::cout << "--------------------------------------------------------------" << std::endl;

	if( state == RedWon )
	{
		int aliveUnitsCount = 0;

		for( int i = 0; i < _red.size(); ++i )
		{
			if( _red[i]->getCurentHP() != 0 )
			{
				std::cout << "Unit #" << i << ": Remaining HP - " << _red[ i ]->getCurentHP() << std::endl;
				++aliveUnitsCount;
			}
		}

		std::cout << "Alive units left: " << aliveUnitsCount << std::endl;
	}
	else
	{
		int aliveUnitsCount = 0;

		for( int i = 0; i < _blue.size(); ++i )
		{
			if( _blue[i]->getCurentHP() != 0 )
			{
				std::cout << "Unit #" << i << ": Remaining HP - " << _blue[ i ]->getCurentHP() << std::endl;
				++aliveUnitsCount;
			}
		}

		std::cout << "Alive units left: " << aliveUnitsCount << std::endl;
	}

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Battle finished" << std::endl;
}

int main()
{
	using namespace GameModel;

	ArmyContainer redArmy, blueArmy;

	auto redArmyForFight = prepareRedArmy( redArmy );
	auto blueArmyForFight = prepareBlueArmy( blueArmy );

	Implementation::GameFactory factory;

	std::unique_ptr< Fight > battle = factory.createFight( redArmyForFight, blueArmyForFight );

	simulateFight( *battle, redArmyForFight, blueArmyForFight );

	return 0;
}