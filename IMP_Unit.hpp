#ifndef _IMP_UNIT_HPP_
#define _IMP_UNIT_HPP_

#include "API_Unit.hpp"

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Unit : public GameModel::Unit
	{
		
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:

		Unit()
		{};

		Unit ( const double & _maxHP
			 , const double & _attackRate
			 , const double & _defenseRate )

			:	  m_maxHP ( _maxHP )
				, m_attackRate ( _attackRate )
				, m_defenseRate ( _defenseRate )
		{}
		
		Unit(const Unit & _other) = delete;
		Unit & operator = (const Unit & _other) = delete;


		Unit(double _curentHP, double _maxHP, double _attackRate, double _defenseRate)
		: m_curentHP ( _curentHP ), m_maxHP ( _maxHP ), m_attackRate ( _attackRate ), m_defenseRate ( _defenseRate )
		{}
		
		virtual double getCurentHP() const override;
		virtual void setCurentHP(double _other) override;

		virtual double getMaxHP() const override;
		virtual double getAttackRate() const override;
		virtual double getDefenseRate() const override;



//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	private:

		double m_curentHP;
		double m_maxHP;
		double m_attackRate;
		double m_defenseRate;
	
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
 

#endif // !_IMP_UNIT_HPP_
