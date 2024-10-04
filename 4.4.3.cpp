#include <iostream>
#include <stdexcept>


template<typename Temp>
class MyVector
{
public:
   MyVector()
      : data(nullptr), myvector_size(0), myvector_capacity(0)
   {}

   ~MyVector()
   {
      delete[] data;
   }

   int size() const
   {
      return myvector_size;
   }

   int capacity() const
   {
      return myvector_capacity;
   }

   void push_back(const Temp& value)
   {
      if (myvector_size == myvector_capacity)
      {
         resize();
      }

      data[myvector_size] = value;
      ++myvector_size;
   }

   Temp& at(int index)
   {
      if (index < 0 || index >= myvector_size)
      {
         throw "Index out of range";
      }

      return data[index];
   }

   Temp& operator[](int index)
   {
      return data[index];
   }

private:
   Temp* data;

   int myvector_size;
   int myvector_capacity;

   void resize()
   {
      if (myvector_capacity == 0)
      {
         myvector_capacity = 1;
      }
      else
      {
         myvector_capacity *= 2;
      }

      Temp* new_data = new Temp[myvector_capacity];

      for (int i = 0; i < myvector_size; ++i)
      {
         new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
   }
};

int main()
{
   MyVector<int> my_vector;

   my_vector.push_back(10);
   my_vector.push_back(20);
   my_vector.push_back(30);

   std::cout << "Size: " << my_vector.size() << std::endl;
   std::cout << "Capacity: " << my_vector.capacity() << std::endl;

   my_vector.push_back(20);

   std::cout << "Size: " << my_vector.size() << std::endl;
   std::cout << "Capacity: " << my_vector.capacity() << std::endl;

   my_vector.push_back(30);
   
   std::cout << "Size: " << my_vector.size() << std::endl;
   std::cout << "Capacity: " << my_vector.capacity() << std::endl;

   for (int i = 0; i < my_vector.size(); i++)
   {
      std::cout << my_vector.at(i) << std::endl;
   }

   std::cout << "Waiting for error" << std::endl;

   my_vector.at(500);
}
