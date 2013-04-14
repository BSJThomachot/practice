#ifndef __HASHENTRY_H_
#define __HASHENTRY_H_

class HashEntry
{
private:
      int m_key;
      int m_value;
	  // can add a pointer to the next element!

public:
      HashEntry(int key, int value)
	  {
            m_key = key;
            m_value = value;
      }
 
      int GetKey() 
	  {
            return m_key;
      }
 
      int GetValue()
	  {
            return m_value;
      }
};

#endif 