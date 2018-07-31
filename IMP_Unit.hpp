#ifndef _IMP_UNIT_HPP_
#define _IMP_UNIT_HPP_

#include "API_Unit.hpp"

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	template< typename _BaseClass >
	class Unit : public _BaseClass
	{
		
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:

		Unit ( const double & _maxHP
			 , const double & _attackRate
			 , const double & _defenseRate )

			:	  m_maxHP ( _maxHP )
				, m_attackRate ( _attackRate )
				, m_defenseRate ( _defenseRate )
			,	m_curentHP( _maxHP )
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

	template< typename _BaseClass >
	double Unit< _BaseClass >::getCurentHP() const
	{
		return m_curentHP;
	}

	template< typename _BaseClass >
	void Unit< _BaseClass >::setCurentHP(double _other)
	{
		m_curentHP = _other;
	}

	template< typename _BaseClass >
	double Unit< _BaseClass >::getMaxHP() const
	{
		return m_maxHP;
	}

	template< typename _BaseClass >
	double Unit< _BaseClass >::getAttackRate() const
	{
		return m_attackRate;
	}

	template< typename _BaseClass >
	double Unit< _BaseClass >::getDefenseRate() const
	{
		return m_defenseRate;
	}
	

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
 

#endif // !_IMP_UNIT_HPP_
