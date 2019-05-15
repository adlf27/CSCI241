#include "Queue.h"
#include <stdexcept>
using std::underflow_error;

/*************************************************
Name:Queue()
use: defualt construnctor, sets queue to 
inital state
Arguments: none
returns:none
 ************************************************/
Queue::Queue()
{
  queueSize = 0;
  queueCap = 0;
  queueArray = nullptr;
  frontSub = 0;
  backSub = queueCap - 1;
}

/*************************************************
Name:Queue()
use: copy consturctor. copies a new object with 
an existing object
Arguments: reference to a cosnt class object
returns:none
 ************************************************/
Queue::Queue(const Queue& other)
{
  queueCap = other.queueCap;
  queueSize = other.queueSize;
  queueArray = new int[queueCap];
  
  //for loop to copy queue arrays
  for(size_t i=0; i<(queueCap - 1);i++)
    queueArray[i] = other.queueArray[i];
  
  frontSub = other.frontSub;
  backSub = other.backSub;
}

/*************************************************
Name:~Queue()
use: Destructor. frees up memery allocated
Arguments: none
returns:none
 ************************************************/
Queue::~Queue()
{
  delete [] queueArray;
}

/*************************************************
Name:clear()
use: clears the queue. set queue to initial state
Arguments: none
returns: none
 ************************************************/
void Queue::clear()
{
  queueSize = 0;
  frontSub = 0;
  backSub = queueCap - 1;
}

/*************************************************
Name:size()
use: get sizes of queue Array
Arguments: none
returns: size_t (unsigned int)
 ************************************************/
size_t Queue::size()const
{
  return queueSize;
}

/*************************************************
Name:capacity()
use: gets the capacity of the queue
Arguments: none
returns:size_t (unsigned int)
 ************************************************/
size_t Queue::capacity()const
{
  return queueCap;
}

/*************************************************
Name:empty()
use: tells wethear the queue is empty or not
Arguments: none
returns: boolean value
 ************************************************/
bool Queue::empty()const
{
  if(queueSize == 0)
    return true;
  else
    return false;
  return(-1);
}

/*************************************************
Name:operator<<
use: dispays out object using cout
Arguments: reference to an ostream object and
reference to a const class queue object
returns:ostream object
 ************************************************/
ostream &operator<<(ostream &out, const Queue &obj)
{
  size_t current, i;
      
  for (current = obj.frontSub, i = 0; i < obj.queueSize; ++i)
   {
   // Print queue element at subscript i
     out << obj.queueArray[current] << ' ';
   
   // Increment i, wrapping around to front of queue array if necessary     
     current = (current + 1) % obj.queueCap;
   }
  return out;
}

/*************************************************
Name:push()
use:adds a value to the queue 
Arguments: integer, represents the num to adds
 to the queue array 
returns:none
 ************************************************/
void Queue::push(int num)
{
  if(queueSize == queueCap)
    {
      if(queueCap == 0)
	reserve(1);
      else
	reserve(queueCap*2);
    }
  backSub = (backSub+1) % queueCap;
  queueArray[backSub] = num;
  ++queueSize;
}

/*************************************************
Name:reserve()
use: reserves additional capacity for the queue
Arguments: size_t
returns:none
 ************************************************/
void Queue::reserve(size_t var)
{
  int *tempArr;
  int currCap;
  if(var > queueCap)
    {
      tempArr = new int[var];
      currCap = frontSub;
      for(unsigned int i=0; i<queueSize;i++)
	{
	  tempArr[i] = queueArray[currCap];
	  currCap = (currCap+1) % queueCap;
	}
      queueCap = var;
      frontSub = 0;
      backSub = queueSize - 1;
      delete [] queueArray;
      queueArray = tempArr;
    }
}

/*************************************************
Name:pop()
use:removes the front sub in the queue 
Arguments:none 
returns:none
 ************************************************/
void Queue::pop()
{
  if(empty())
    throw underflow_error("Queue underflow.");
  else
    {
      frontSub = (frontSub + 1) % queueCap;
      queueSize--;
    }
      
}

/*************************************************
Name:front
use: get the front sub from the queue
Arguments: none
returns:integer the front subscript
 ************************************************/
int Queue::front()const
{
  if(empty())
    throw underflow_error("Queue underflow");
  else
    return queueArray[frontSub];  
}

/*************************************************
Name:back()
use: gets the back subscript
Arguments: none
returns:integer back susbcript
 ************************************************/
int Queue::back()const
{
  if(empty())
    throw underflow_error("Queue underfow");
  else
    return queueArray[backSub]; 
}

/*************************************************
Name:operator==
use: allows one queue to be set to another
Arguments: reference to a const queue object
returns:class object of Queue
 ************************************************/
Queue &Queue::operator=(const Queue& other)
{
  if(&other != this)// checks for self assignment
    {
      delete [] queueArray;
      queueCap = other.queueCap;
      queueSize = other.queueSize;
      queueArray = new int[queueCap];
      
      //for loop to copy the queue arrays
      for(size_t i = 0; i < queueCap; i++)
	queueArray[i] = other.queueArray[i];
      
      frontSub = other.frontSub;
      backSub = other.backSub;
    }
  return *this;
}
