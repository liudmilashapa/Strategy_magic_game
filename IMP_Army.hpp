#ifndef _IMP_ARMY_HPP_
#define _IMP_ARMY_HPP_

#include <map>
#include <memory>

#include "API_Army.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Army : public GameModel::Army
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		Army(int _ID, int _maxArmyCount)
		:	m_ID( _ID ),
			m_maxUnitsCount( _maxArmyCount )
		{}

		Army(const Army & _other) = delete;
		Army & operator = (const Army & _other) = delete;

		virtual int getArmySize() const override;
		virtual int getMaxUnitsCount() const override;
		virtual int getID() const override;
		virtual double getHPForID(int _id) const override;
		virtual GameModel::Unit & getUnitForID( int _id ) const override;

		virtual bool hasUnitInArmy( int _id ) const override;
		virtual bool hasArmyDistroed() const override;

		virtual void addUnit( std::unique_ptr< GameModel::Unit > _unit) override;
		virtual void removedUnit( int _id ) override;
		virtual  std::optional < GameModel::Unit * > findUnit(int _id) const override;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:

		armyContainer m_army;
		int m_maxUnitsCount;
		int m_ID;
		void isAmyFullness() const;

	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

}//Implementation
}// namespace GameModel

  //*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif // !_IMP_ARMY_HPP_
