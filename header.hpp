#include <iostream>
#include <cstdlib>
#ifndef HASH_H
#define HASH_H

struct Hash
{
  static const int Size = 101;

  typedef struct item
  {
    std::string word;
    std::string mean;
    item *next;
  } *itemPtr;

  itemPtr HashTable[Size];


  int hash (std::string key);
      Hash();
  void addItem (std::string word, std::string mean);
  void searchForWord (std::string word);

 
};

Hash::Hash ()
{		
  for (int i = 0; i < Size; i++)
    {
      HashTable[i] = new item;
      HashTable[i]->word = "empty";
      HashTable[i]->mean = "empty";
      HashTable[i]->next = NULL;
    }

  std::ifstream inFile ("dictionary.txt");
  std::string word;
  std::string mean;
  
  while (inFile>>word>>mean)
    {  
      addItem (word, mean);
    }

}

int Hash::hash (std::string key)
{		
  int hash = 0;
  int index;

  for (int i = 0; i < key.length (); i++)
    {
      hash = hash + ((int) key[i]) * 5;
    }
  std::cout << std::endl;

  index = hash % Size;

  return index;

}

void Hash::addItem (std::string word, std::string mean)
{		
  int index = hash (word);

  if (HashTable[index]->word == "empty")
    {		
      HashTable[index]->word = word;
      HashTable[index]->mean = mean;
    }
  else
    {
      itemPtr n = HashTable[index];
      itemPtr p = new item;
      p->word = word;
      p->mean = mean;
      p->next = NULL;

      while (n->next != NULL)
	{
	  n = n->next;
	}
      n->next = p;
    }

}


void Hash::searchForWord (std::string word)
{		

  for (int i = 0; i < Size; i++)
    {
      itemPtr p = HashTable[i];
      while (p != NULL)
	{
	  if (p->word == word)
	    {

              std::cout<< "the meaning of "<< p->word << " is " << p-> mean<< std::endl;
	      break;
	    }
	  else
	    {
	      p = p->next;
     
	    }

	}


    }


}


#endif
