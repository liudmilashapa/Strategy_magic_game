#include < memory >

#include "API_Ability_Unit.hpp"


#include "IMP_Ability_Unit.hpp"
#include "IMP_Factory.hpp"
#include "IMP_Fight.hpp"
#include "IMP_Magic_Unit.hpp"
#include "IMP_Unit.hpp"
#include "Spell.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	std::unique_ptr < GameModel::Unit > GameFactory::createUnit (
		  const double & _maxHP
		, const double & _attackRate
		, const double & _defenseRate
	) const
	{
		return std::unique_ptr < GameModel::Unit > ( new GameModel::Implementation::Unit< GameModel::Unit > (
			  _maxHP
			, _attackRate
			, _defenseRate
		));
	}

	std::unique_ptr < GameModel::MagicUnit > GameFactory::createMagicUnit (
		  const double & _maxHP
		, const double & _attackRate
		, const double & _defenseRate
		, const double & _maxMPU
		, const spellContainer & _spells
	) const
	{
		return std::unique_ptr < GameModel::MagicUnit > ( new GameModel::Implementation::MagicUnit (
			_maxHP
			, _attackRate
			, _defenseRate
			, _maxMPU
			, _spells
		));
	}

	std::unique_ptr < GameModel::AbilityUnit > GameFactory::createAbilityUnit(
		  const double & _maxHP
		, const double & _attackRate
		, const double & _defenseRate
	) const
	{
		return  std::unique_ptr < GameModel::AbilityUnit > ( new AbilityUnit (
			 _maxHP
			, _attackRate
			, _defenseRate
		));
	}

	std::unique_ptr < GameModel::Fight > GameFactory::createFight(
		  fightContainer & _army1
		, fightContainer & _army2
	) const
	{
		return  std::unique_ptr < GameModel::Fight >(new Fight(
			  _army1
			, _army2
		)
		);
	}

	std::unique_ptr < GameModel::Spell > GameFactory::createSpell(
		const double & _cost
	) const
	{
		return std::unique_ptr < GameModel::Spell >(new GameModel::Spell (
			_cost
		));
	}

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//



//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

  //*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
