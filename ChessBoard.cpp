#include <iostream>

class PiecesOnChessBoard {
friend class SideOfChessBord;
private:
	char* listOfCells;
	int arraySize;
public:
	PiecesOnChessBoard(char* _array, int sizeArray) {
		arraySize = sizeArray;
		listOfCells = new char[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			listOfCells[i] = _array[i];
		}
	}
private:
	void ShowWhitSide() {
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << listOfCells[i] << "\t";
			i++;
			if (i%10 == 0)
				std::cout << std::endl;
			i--;
		}
	}
	void ShowBlackSide() {
		for (int i = 199; i > arraySize; i--)
		{
			std::cout << listOfCells[i-100] << "\t";
			if (i % 10 == 0)
				std::cout << std::endl;
		}
	}
	~PiecesOnChessBoard() {
		delete[] listOfCells;
	}
};

class SideOfChessBord {
public:
	char* _listOfCells;
	int _arraySize;
	SideOfChessBord(char* _array, int sizeArray) {
		_arraySize = sizeArray;
		_listOfCells = new char[_arraySize];
		for (int i = 0; i < _arraySize; i++)
		{
			_listOfCells[i] = _array[i];
		}
	}
	void setParameters(PiecesOnChessBoard& c) {
		std::cout << "Розташування фігур з погляду гравця білими" << std::endl;
		c.ShowWhitSide();
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "Розташування фігур з погляду гравця чорними" << std::endl;
		c.ShowBlackSide();
	}
};




int main() {
	system("chcp 1251>nul");
	const int _arraySize = 100;
	char cellsOnBord[_arraySize] = {'.','a','b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'.' 
	,'8' ,'Т' ,'к' ,'С' ,'Ф' ,'К' ,'С' ,'к' ,'Т' ,'8'
	,'7' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'7'
	,'6' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'6' 
	,'5' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'5'
	,'4' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'4'
	,'3' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'3'
	,'2' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'п' ,'2'
	,'1' ,'Т' ,'к' ,'С' ,'Ф' ,'К' ,'С' ,'к' ,'Т' ,'1'
	,'.','a','b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'.' };

	PiecesOnChessBoard* Bord = new PiecesOnChessBoard(cellsOnBord,_arraySize);
	SideOfChessBord* Side = new SideOfChessBord(cellsOnBord, _arraySize);
	Side->setParameters(*Bord);
	return 0;
}