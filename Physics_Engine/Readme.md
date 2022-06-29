# Dokumentation Physics-Engine 
  
 Dieses Projekt wird von Linus Schweizer und Gabriel Kraus entwickelt, bei dem Linus zum größten Teil die Dokumentation und Gabriel zum größten Teil den Programmcode schreibt. Die nötige Mathematik haben wir gemeinsam (klasisch mit Stift und Papier) entwickelt.  
  
  
 ## Klassenhierarchie 
  Die Klassenhierachie zeigt, wie viele Dateien (und später auch Klassen) enthält/enthalt wird. Im laufe der Zeit werden es definitv noch mehr.  
  

  
 ````mermaid 
     graph LR;   
     Circle.hpp-->Shape([Shape]); 
     Circle.cpp-->Shape([Shape]); 
     Polygon.hpp-->Shape([Shape]); 
     Polygon.cpp-->Shape([Shape]); 
     Run.cpp-->Game([Game]) 
     Run.hpp-->Game([Game]) 
     Error.cpp-->Exception([Exception]) 
     Error.hpp-->Exception([Exception]) 
     Exception-->Run.hpp 
     Exception-->Polygon.hpp  
     Exception-->Circle.hpp  
     Game-->main.cpp 
     Shape-->main.cpp; 
 ```` 
 
>
Eventuell muss der mermaid Code sepperat eingesehen werden(z.B. im Internt) da mermaid nur sehr umständlich zu PDF konvertiert werden kann.  
> 
  
  
 ## Collision 
 In der Collision Klasse werden später Objekte von Formen übergeben um zu überprüfen, ob Objekte miteinander kollidieren. Die syntax für die Collision funktion sieht etwa so aus:  
  
 ### Collision 
  
 ````CPP 
 friend void check_collision(Cirle& a, Cirlce& b) { 
     if( sqrt(pow((b.pos.x - a.pos.x), 2) + pow((b.pos.y - a.pos.y), 2)) > a.r + b.r) { 
         return false;  
     } 
     else  
     { 
         return true;  
     } 
 } 
 ```` 
 Mathematisch sieht das dann etwa so aus:  
 $\large Kollision \space = \space \sqrt{(a_{x} + b_{x})^2 + (a_{y} + b_{y})^2} \leq a_{r} + b_{r}$ 
 Wenn die strecke $\Delta s$  kleiner gleich der Strecke $\Delta r$ (Summe der beiden Radien) entspricht. Allerdings ist diese Funktion noch nicht
  implementiert (die Mathe jedoch steht schon).  

### SAT (Seperate Axis Theorem)


##### _Dot Produkt_

$\begin{bmatrix}A_x \\A_y\end{bmatrix}.  \begin{bmatrix}B_x \\B_y\end{bmatrix}=  (A_x)(B_x)+(A_y)(B_y)$

Alternativ : 

$\begin{bmatrix}A_x \\A_y\end{bmatrix}.  \begin{bmatrix}B_x \\B_y\end{bmatrix}=  A_{magnitude}*B_{magnitude}*cos(theta)$



$A. P=A_{magnitude} \cdot P_{magnitude}*cos(theta)\\  A.\frac{P}{P_{magnitude}}=A_{magnitude}\cdot cos(theta)\\  \begin{bmatrix}A_x \\A_y\end{bmatrix}.  \begin{bmatrix}P_x/P_{magnitude}\\P_y/P_{magnitude}\end{bmatrix}=A_{magnitude} \cdot cos(theta)$



 ## ExceptionHandling 
 Hier werden später ungewollte Probleme behandelt, z.B. Overflows von Arrays oder ähnlichem.  
  
 ###  Error 
 > _comming ..._ 
  
 ## Run 
 Im game Ordener werden Objekte an SFML übergeben und dann auf dem Bildschirm dargestellt. Jedoch muss der Code dazu erst noch geschrieben werden ;).    
  
 ### run 
 > _comming ..._ 
  
  
  
 ## Shape 
 Im Shape Ordner werden jegliche Arten von Shapes gespeichert. Für komplexe und einfache Shapes gibt es die  shape-Klasse, aber dazu später mehr. Für Kreise gibt es eine eigene Klasse, da er nicht wirklich einer Form entsprechen, da Kreise keine Ecken haben und somit auch keine Punkte (die eine Ecke repräsentieren könnten).  
  
 ### Circle 
 Die Circle Klasse ist eine eher simple Klasse. Da ein Kreis nur einen Radius und eine Position braucht, enthält die Klasse fast nichts. Wir möchten jedoch den Code(exsistiert noch nicht, die Schnittstellen allerdings schon) nicht vorweg nehmen.  
  
 
 ```CPP
class Circle 
{ 
 private: 
	  vec2 pos {0, 0};  
      float radius { 1 };  
      std::string name {"NULL"};  
 public:  
      Circle() = default;   
      Circle(const float);  
      Circle(const float, const std::string);  
      Circle(const float, const std::string, const vec2); 
      Circle(const float, const std::string, const float, const float); 
      ~Circle() = default;
public: 
	vec2 get_Position(const bool) const;
	std::string get_name(const bool) const;
	float get_radius(const bool) const;
	float get_pos_x(const bool) const;
	float get_pos_y(const bool) const; 
public:
	void set_position(const vec2);
	void set_position(const float, const float);
	void set_name(const std::string);
	void set_radius(const float);
}; 
 ```
 
 
Die Circle-Klasse hat oben aufgelistete Funktionen. Sie hat 5 Konstruktoren (C-tor's), einen default Destructor (D-tor) und mehrere Funktionen um Variabelwerte zurueck zu bekommen. Im private-Bereich (der default immer private ist) gibt es einen _vec2_ der die Position des Kreises speichert. Fuer den Fall das der Kreis bei der Initialisierung keine Position bekommt, hat er standart maessig die Position $\large P_{kreis}(0,0)$. 

```CPP 
class Circle 
{ 
private: 
	vec2 pos {0,0};	
}
```

Ausserdem gibt es eine Variable _radius_ die vom Typ float ist. Der Radius wird benoetigt um zu kalkulieren ob es eine Kollision zwischen zwei Objekten gibt und natuerlich die groesse des Kreises zu bestimmen. Der Radius ist default (fuer den Fall das er nicht initiallisiert wird auf 1 gesetzt, um den Einheitskreis wiederzuspiegeln). 

> 
> Die Initalsierung von Variablen durch geschweifte Klammer kann unter Umständen zu Verwirrung führen, jedoch ist das seit C++11 möglich und wird gerne von Entwicklern verwendet. Natuerlich ist es immer noch moeglich mit dem "$=$" Operator zu initialisieren, jedoch wird er eher fuer zuweisungen genutzt. 
> Es geht uebrigens auch beides :
```CPP
	int var1 = { 0 }; //ungewohnlich, geht aber
	
	int var2 = 1;  // alte Art der Initialisierung duch den zuweisungsoperator
	
	int var3 { 2 } // Initialisierung durch geschweifte Klammern, seit C++11
``` 

```CPP 
class Circle 
{ 
private: 
	vec2 pos {0,0};	
	float radius { 1 }; 
}
```

Es steht auch zur Moeglichkeit dem Kreis einen Namen zu geben (allerdings wird diesser nicht bei einer Simulation angezeigt). Die Idee dahinter ist den Ueberblick ueber Objekte zu behalten und diese mit dem Namen anzusprechen. Der Datentyp fuer den Name ist ein String. Strings in C++ sind "etwas" speziell, da sie einmal als alten Char-Array betrachtet werden aber auch als modernes C++ Objekt. 

>
>char ist ein Datentyp der einfache Zeichen speichern kann. Die Zuweisung ist fast genau so wie bei normalen Zahlen, jedoch ist zu beachten das Die zuweisung entweder eine Zahl (die dann das Zeichen an der Stelle im ASCII-Code laedt) oder ein Zeichen das allerdings zwischen zwei Hochkommas stehen muss ( ' ' ) . Chars kennt man vielleicht aus anderen Programmiersprachen z.B. JAVA oder Python. In C++ hat ein im Speicher 2 Bytes (2 x 8 Bits). Es gibt allerdings auch noch Chars die weit aus mehr Speicher reservieren um komplexer Zeichen (z.B. Chinesisch) zu speichern. Diese haben dann bis zu 64 Bit (abhaenig vom genutzten Compiler). 
```CPP
	char someChar { 'a' }; //einfaches Alphabet / ASCII Zeichen
	wchar_t anotherChar {''}; //kann komplexe ASCII Zeichen speichern und ausgeben
```


```CPP
class Circle 
{
private:
	vec2 pos{0 , 0};
	float radius { 1 };
	std::string name = {"NULL"}; 
}
```

##### STD Template library und  Strings
>_comming soon ..._



 ### Polygon 


 Das Polygon ist ein etwas komplizierteres Konstrukt. Deswegen gibt es im Standart-Konstruktor (kurz Ctor von Constructor) einen Funktions aufruf, der die Funktion 
 RegularPolygon() aufruft.  



### RegularPolygon(const float, const int))

Dabei wird in einem Ctor mitgegeben die Anzahl der Ecken regelmaessig  auf einem imagineren Kreis verteilt.  Um einen beliebigen Punkt $P {_i}$
zu erechnen wird folgendes Berechnung für die x Koordinate durchgefuehrt:  
  
${\large   x = cos(\frac{2 \cdot \pi \cdot i}{n}) \cdot r}$ 
  
und für die y Koordinate:  
  
 ${\large   y = sin(\frac{2 \cdot \pi \cdot i}{n}) \cdot r}$ 
 
 und alles zusammengesetzt ergibt das dann den Punkt:  
  
   ${{\large P _i = \biggl \lgroup cos \biggl( \frac{2 \cdot \pi \cdot i}{n} \biggr ) \cdot r \space , \space sin \biggl(\frac{2 \cdot \pi \cdot i}{n} \biggr) \cdot r }\biggr \rgroup}$ 
  
 bei dem $i$ die Anzahl des jetzigen Punktes, $n$ die Anzahl der totalen Punkte und $r$ dem Radius des imaginären Kreises entspricht. Die Funktion dazu sieht folgender maßen aus.  
 Zuerst wird ein Struct "vec2" erstellt. Das ist eine Art selbstgeschriebener Datentyp der in C++ als Object gehandelt wird. Die Sytax für ein Struct sieht folgender maßen aus.  
  
 ````CPP 
 struct NAME { 
     DATENTYP1 var1;  
     DATENTYP2 var2;  
     ... 
 };  
 ```` 
 
 temp repräsentiert in diesem Fall ein Punkt der im forloop ständig neu ausgerechnet und überschrieben wird. Er macht es um einiges leichter in den vector points vom Datetyp 
 "vec2" Elemente zu "push_back" (VECTORNAME.push_back(OBJEKT-NAME) schiebt ein Element/Objekt an die erste freie Position in einem Vector). Nachdem wird die totale Winkelsumme ausgerechnet und ausgegeben. Genau so, für einen Winkel (der immer kleiner gleich 180° ist) an einem Punkt $P_nder zwischen $P_{n - 1}$ und $P_{n+1}$liegt. Der erste Punkt wird nochmals an letzte Stelle gepusht, da sonst eine Seite des 
 Polygons fehlt.  
  
 ````CPP 
 void PhysicsEngine::Shape::Polygon::RegularPolygon(float r, int n)  
 {    
     PhysicsEngine::vec2 temp {0, 0};  
     float TotalAngleSum = (n - 2) * 180;  
     float angle = 360 / n;  
  
     std::cout << "\nTotal Angle Sum equals: " << TotalAngleSum << "\nOne Angle equals: " << angle << "\n\n" << std::endl;  
  
  
     for( int i = 0; i < n; i++)  
     { 
         temp.x = cos((2 * PI * i) / n) * r;   
         temp.y = sin((2 * PI * i) / n) * r;  
         points.push_back(temp);  
         std::cout << "x: " << std::fixed << temp.x << "\ty: " << std::fixed << temp.y << std::endl;      
     } 
  
     temp.x = cos((2 * PI * 0) / n) * r;   
     temp.y = sin((2 * PI * 0) / n) * r;  
     points.push_back(temp);  
  
 } 
 ```` 
  
 ## Ziele 
 > _comming soon..._ 
  
 ## Quellen 
 > _comming soon..._ 




## Rotation
Die Rotation fuer Polygone funktioniert folgendermassen : 
Zuerst wird von dem alten Punkt $P _{n (old)}$ die x-Koordiate $\large \space x _{old} \space$ mit dem Cosinus von $\large \theta$ multipliziert und danach wird die y-Koordinate $\space \large y _{old} \space$ mit dem Sinus von $\large \theta$ multiplizert und von $\large x_{old} \space \cdot \cos(\theta)$ subtrahiert. Mathematisch geschrieben sieht das dann so aus: 

${\large x _{new}\space = \space x_{old} \space \cdot \space cos(\theta) \space - \space y_{old} \space \cdot \space sin(\theta)}$

Bei der neuen y-Koordinate sieht das ganze aehnlich aus. Zuerst wird $\large x _{old}$ mit dem Sinus multipliziert und dann mit  $\large \space y_{old} \space \cdot \space \cos(\theta) \space$ addiert. Mathematisch ist das dann wie folgt: 
 
${\large y _{new} \space = \space x_{old} \space \cdot \space sin(\theta) \space + \space y _{old} \space \cdot \space cos(\theta)}$

Kurzgesagt, der alte Punkt $P_{n(old)}$ wird zu $P_{n(new)}$  indem wir die alten Koordinaten transfomieren wird : 

$\large P_{n} \space \biggl(x_{old} \space cos(\theta) \space - \space y_{old} \space sin(\theta) \space , \space x_{old} \space sin(\theta) \space + \space y_{old} \space cos(\theta) \biggr)$

> 
Allerdings ist zu beachten das der Winkel θ in rad ist. Um ihn von einem normalen Winkel deg in rad umzurechen wird folgendes gerechnet: 
>
$\Large \theta = \frac{\alpha _{deg} \space \cdot \space \pi} {180 \degree}$
>



Der Code sieht dazu folgendermassen aus: 

```CPP
void PhysicsEngine::Shape::Polygon::setRotation(const float _theta)
{
	if(!this->points.empty())
	{
		std::vector<vec2> _tvec;
		vec2 temp {0, 0};
		float theta= _theta * (PI / 180);
	
		for( int i = 0; i < points.size(); i++)
		{
			temp.x = points.at(i).x * cos(theta) - points.at(i).y * sin(theta);
			temp.y = points.at(i).x * sin(theta) + points.at(i).y * cos(theta);
			_tvec.push_back(temp);
		
		//Control (Debug) 
			std::cout << "x: " << std::fixed << temp.x << "\ty: " << std::fixed << temp.y << std::endl;
	
		}
		
	this->points = _tvec;
	}
} 
```

Erst wird geschaut ob der Vector _points_ Elemente (Punkte) enhaelt. Wenn dass der Fall ist wird ein temporaerer Vector _ _tvec_  erstellt vom Typ _vec2_. 

```CPP 
std::vector<vec2> _tvec; 
```

Ausserdem erstellen wir noch ein Objekt vom Typ _vec2_, mit dessen hilfe es einfacher ist Elemente in den Vector _ _tvec_ einzulesen. Danach rechnen wir $\large \theta$ von $\large deg$ in $\large rad$ um. 

```CPP
vec2 temp {0, 0};
float theta= _theta * (PI / 180);
```

Dann wird wird jeder alte Punkt $\large P_{n}$ nneeu ausgerechnet mit der obigen Formel. Zuerst werden in einer for-Schleife, die die groesse des Arrays _points_ hat, alle Element  an der Position "_n_" (in der Schleife "_i_") neu ausgerechnet und an den Vector "_ _tvec_ " "angereiht". 

```CPP
for( int i = 0; i < points.size(); i++)
{
	temp.x = points.at(i).x * cos(theta) - points.at(i).y * sin(theta);
	temp.y = points.at(i).x * sin(theta) + points.at(i).y * cos(theta);
	_tvec.push_back(temp);
}
```

Danach wird der Vector _points_ durch den Vector "_ _tvec_" ueberschrieben. 

```CPP
this->points = _tvec;
```
