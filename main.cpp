#include <iostream>
#include <cstdlib>
#include <fstream>
#include "header.hpp"


int main ()
{		
  int choice;	

  Hash hashObj;	
   while (choice != 0)
 
    {		
      std::cout << "Would you like to search for a word? "<< std::endl;
      std::cout << "Yes (1) or No (0) >> ";
      std::cin >> choice;
      std::string search;

      switch (choice)
	{

	case 0:
	  std::cout << "Exit :)" << std::endl;
	  break;

	case 1:
	  {
	    std::string search;
	    std::cout << "Enter the word you wish to search for: " << std::endl;
	    std::cin >> search;
	    hashObj.searchForWord (search);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	    break;
	  }
	default:
	  std::cout << "Try Again." << std::endl;


	}
    }


  return 0;
}
