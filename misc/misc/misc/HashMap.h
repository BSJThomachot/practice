#ifndef _HASHMAP_H_
#define _HASHMAP_H_
#include "HashEntry.h"

const int TABLE_SIZE = 128;
 
class HashMap 
{
private:
	HashEntry **table;

public:
	HashMap() 
	{
		table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
		{
                  table[i] = 0;
		}
	}

	~HashMap() 
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
		      if (table[i] != 0)
			  {
		            delete table[i];
			  }
		}
        delete[] table;
    }
 
	int Get(int key)
	{
		int hash = (key % TABLE_SIZE);
        while (table[hash] != 0 && table[hash]->GetKey() != key)
		{
			hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == 0)
			{
                  return -1;
			}
            else
			{
                  return table[hash]->GetValue();
			}
		}
	}
 
    void Set(int key, int value)
	{
		int hash = (key % TABLE_SIZE);
        while (table[hash] != 0 && table[hash]->GetKey() != key)
		{
            hash = (hash + 1) % TABLE_SIZE;
		}
        if (table[hash] != 0)
		{
			delete table[hash];
		}
        table[hash] = new HashEntry(key, value);
	}     
};

#endif