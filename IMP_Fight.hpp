#ifndef _IMP_FIGHT_HPP
#define _IMP_FIGHT_HPP

#include < vector >
#include < memory > 

#include "API_Fight.hpp"
#include "IMP_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	typedef
		std::vector < GameModel::Unit * >
		fightContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Fight : public GameModel::Fight
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		Fight( fightContainer & _army1, fightContainer & _army2 ) 
		:m_army1( _army1 ), m_army2( _army2 )
		{}

		Fight( const Fight & _other ) = delete;
		Fight & operator = ( const Fight & _other ) = delete;

		virtual void singleHit( GameModel::Unit & _unit1, GameModel::Unit & _unit2 ) override;
		virtual void doubleHit(GameModel::Unit & _unit1, GameModel::Unit & _unit2 ) override;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:

		fightContainer m_army1;
		fightContainer m_army2;

		void isUnitInArmy(const fightContainer & _army, const GameModel::Unit & _unit) const;
		void isUnitLive(const GameModel::Unit & _unit) const;
		double calculateDamage(GameModel::Unit & _unit1, GameModel::Unit & _unit2) const;
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif //!_IMP_FIGHT_HPP