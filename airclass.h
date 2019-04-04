#ifndef AIRCLASS_H
#define AIRCLASS_H

#include <string>
#include <vector>

class StringCollectionVentilation
{
private:
protected:
	const std::string printExpSpeed					{ "Expected SpeedAverage" }
					 ,printInsertMeasurementPoint	{ "Please Insert the Measurement-Point: "};
					
public:
	std::string insertMeasurementPoint		{};

	StringCollectionVentilation();
	~StringCollectionVentilation();
};

class TubeProtocol : public StringCollectionVentilation
{
private:
protected:
	double	diameter {}
			,circularArea {}
			,setPointAirVolume {}
			,measuredSpeed {}
			,V_max {}
			,V_min { INT_MAX }
			,sumMeasuredSpeed {}
			,counterSpeedIn {}
			,expAvTube {}
			,averageSpeed {}
			,airVolume {}
			,deviation {};

public:
	std::vector<double> speedMeasurementsCollection{};

	void setMeasurementPoint( const std::string& insertMeasurementPoint );
	void setDiameter( const double& diameter );
	void setCalcCircularArea( const double& diameter);
	void setSetPointAirVolume( const double& airVolume );
	void setMeasuredSpeed( const double& measuredSpeed );
	void setV_Max( const double& V_max );
	void setV_Min( const double& V_min );
	void setV_Sum( const double& sumMeasuredSpeed );
	void setCounterSpeedIn( const double& counterSpeedIn );
	void setCalcSpeedAvInTubes( const double& , const double& );
	void setAverageSpeed( const double& averageSpeed );
	void setAirvolume( const double& airVolume );
	void setDeviation( const double& deviation );
	
	std::string getinsertMeasurementPoint() const;
	std::string speedMeasurementsCollectionToString () const;
	double getDiameter() const;
	double getCalcCircularArea() const;
	double getSetPointAirVolume() const;
	double getV_Max() const;
	double getV_Min() const;
	double getV_Sum() const;
	double getcounterSpeedIn() const;
	double getCalcSpeedAvInTubes() const;
	double getSpeedAverage() const;
	double getAirvolume() const;
	double getDeviation() const;
	std::string toString() const;
    friend std::ostream& operator<<( std::ostream &out, TubeProtocol& printObjects )
	{
		out << printObjects.toString();

		return out;
	}
	
	~TubeProtocol();
};

class ExpSpeedAvInTubes : public TubeProtocol
{
private:
protected:
public:
	void setDiameter( const double& diameter );
	void setCalcCircularArea( const double& diameter);
	void setSetPointAirVolume( const double& airVolume );
	void setCalcSpeedAvInTubes( const double& , const double& ); 

	double getDiameter() const;
	double getCalcCircularArea() const;
	double getSetPointAirVolume() const;
	double getCalcSpeedAvInTubes() const;
	std::string toString() const;
    friend std::ostream& operator<<( std::ostream &out, ExpSpeedAvInTubes& printObjects )
	{
		out << printObjects.toString();

		return out;
	} 

	~ExpSpeedAvInTubes();
};

class DuctProtocol : public StringCollectionVentilation
{
private:
protected:
	double	width {}
			,height {}
			,orthogonArea {}
			,setPointAirVolume {}
			,measuredSpeed {}
			,V_max {}
			,V_min { INT_MAX }
			,sumMeasuredSpeed {}
			,counterSpeedIn
			,expAvDuct {}
			,averageSpeed {}
			,airVolume {}
			,deviation {};

public:
	std::vector<double> speedMeasurementsCollection{};

	void setMeasurementPoint( const std::string& insertMeasurementPoint );
	void setWidth( const double& width );
	void setHeight( const double& height );
	void setCalcOrthogonArea( const double& width, const double& height);
	void setSetPointAirVolume( const double& airVolume );
	void setMeasuredSpeed( const double& measuredSpeed );
	void setV_Max( const double& V_max );
	void setV_Min( const double& V_min );
	void setV_Sum( const double& sumMeasuredSpeed );
	void setCounterSpeedIn( const double& counterSpeedIn );
	void setCalcSpeedAvInDucts( const double& setPointAirVolume, const double& orthogonArea );
	void setAverageSpeed( const double& averageSpeed );
	void setAirvolume( const double& airVolume );
	void setDeviation( const double& deviation );

	std::string getinsertMeasurementPoint() const;
	std::string speedMeasurementsCollectionToString() const;
	double getSetPointAirVolume() const;
	double getWidth() const;
	double getHeight() const;
	double getCalcOrthogonArea() const;
	double getV_Max() const;
	double getV_Min() const;
	double getV_Sum() const;
	double getcounterSpeedIn() const;
	double getCalcSpeedAvInDucts() const;
	double getSpeedAverage() const;
	double getAirvolume() const;
	double getDeviation() const;
	std::string toString() const;
	friend std::ostream& operator<<( std::ostream &out, DuctProtocol& printObjects )
	{
		out << printObjects.toString ();

		return out;
	}
	
	~DuctProtocol();
};

class ExpSpeedAvInDucts : public DuctProtocol
{
private:
protected:

public:
	void setWidth( const double& width );
	void setHeight( const double& height );
	void setCalcOrthogonArea( const double& width, const double& height);
	void setSetPointAirVolume( const double& airVolume );
	void setCalcSpeedAvInDucts( const double& setPointAirVolume, const double& orthogonArea );

	double getWidth() const;
	double getHeight() const;
	double getCalcOrthogonArea() const;
	double getSetPointAirVolume() const;
	double getCalcSpeedAvInDucts() const;
	std::string toString() const;
	friend std::ostream& operator<<( std::ostream &out, ExpSpeedAvInDucts& printObjects )
	{
		out << printObjects.toString ();

		return out;
	} 
	
	~ExpSpeedAvInDucts();
};

class VAVProtocol : public StringCollectionVentilation
{
private:
	unsigned int deputySig {}
				,spinDir {};

		double setPointAirVolume {}
				,V_max {}
				,V_min { INT_MAX }
				,V_nom
				,deviation {}
				,maxAirVolume {}
				,minAirVolume {};

	std::string deputySigStr {};
	std::string spinDirStr {};

protected:
public:
	void setMeasurementPoint( const std::string& insertMeasurementPoint );
	void setSetPointAirVolume( const double& setPointAirVolume );
	void setV_Nom( const double& V_nom );
	void setV_Min( const double& V_min );
	void setV_Max( const double& V_max );
	void setDeputySignal( const std::string& deputySig );
	void setSpinDirection( const std::string& spinDir );
	void setMaxAirvolume ( const double& airVolume );
	void setMinAirvolume ( const double& airVolume );
	void setDeviation( const double& deviation );

	std::string getinsertMeasurementPoint() const;
	double getSetPointAirVolume() const;
	double getV_Nom() const;
	double getV_Min() const;
	double getV_Max() const;
	std::string getDeputySignal() const;
	std::string getSpinDirection() const;
	double getMaxAirvolume() const;
	double getMinAirvolume() const;
	double getDeviation() const; 
	std::string toString() const; 
	friend std::ostream& operator<<( std::ostream &out, VAVProtocol& printObjects )
	{
		out << printObjects.toString ();

		return out;
	}

	~VAVProtocol();
};

class VentilatorPressure
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };
protected:
public:
	VentilatorPressure();
	~VentilatorPressure();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Dummy8
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy8();
	~Dummy8();
};

class Dummy9
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy9();
	~Dummy9();
};

class Dummy10
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy10();
	~Dummy10();
};

class Dummy11
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy11();
	~Dummy11();
};

class Dummy12
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy12();
	~Dummy12();
};

class Dummy13
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy13();
	~Dummy13();
};

class Dummy14
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy14();
	~Dummy14();
};

class Dummy15
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy15();
	~Dummy15();
};

class Dummy16
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy16();
	~Dummy16();
};

class Dummy17
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy17();
	~Dummy17();
};

class Dummy18
{
private:
	const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy18();
	~Dummy18();
};

class Dummy19
{
private:
	 const std::string printEmptyFunc	  { "   This Function is Empty!" };

public:
	Dummy19();
	~Dummy19();
};
#endif // AIRCLASS_H
