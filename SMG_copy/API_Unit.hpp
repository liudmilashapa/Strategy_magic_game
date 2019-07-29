#ifndef _API_UNIT_HPP_
#define _API_UNIT_HPP_



//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Unit
	{
		
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:
	
		Unit()
		{}
		
		virtual double getCurentHP() const  = 0;
		virtual void changeCurentHP(double _other) = 0;

		virtual double getMaxHP()  const  = 0;
		virtual double getAttackRate()  const = 0;
		virtual double getDefenseRate()  const = 0;
		virtual int getUnitID() const = 0;


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	private:

	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif // !_API_UNIT_HPP_
