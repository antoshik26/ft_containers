#ifndef ITERATORVECTOR_HPP
#define ITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>


namespace ft
{
	template<typename T>
	class ConstIteratorVector;

	template<typename T>
	class IteratorVector
	{
		public:
			typedef std::random_access_iterator_tag                 iterator_category;
			typedef long int                                        difference_type;
			typedef T                                               value_type;
			typedef size_t                                          size_type;		
			typedef T*                                              pointer;
			typedef T&												reference;
			
		private:
			T* obj;
		public:
			IteratorVector()
			{
				obj = NULL;
			}

			IteratorVector(T* first)
			{
				obj = first;
			}

			~IteratorVector()
			{
			}

			IteratorVector& operator=(const IteratorVector& it)
            {
                if (this != &it)
                    obj = it.obj;
                return (*this);
            }
			
			IteratorVector& operator+=(int nb)
            {
                movePtr(this->obj, nb, 1);
                return (*this);
            }

			IteratorVector& operator-=(int nb)
            {
                movePtr(this->obj, nb, 0);
                return (*this);
            }


			IteratorVector operator+(int nb) const
            {
                IteratorVector it(*this);
                
                movePtr(it.obj, nb, 1);
                return (it);
            }
			
			friend IteratorVector operator+(int nb, const IteratorVector& obj)
            {
            	IteratorVector newIt(obj);
            	return (newIt += nb);
            }

			IteratorVector operator-(int nb) const
            {
                IteratorVector it(*this);
                
                movePtr(it.obj, nb, 0);
                return (it);
            }

            friend IteratorVector operator-(int nb, const IteratorVector& obj)
            {
                IteratorVector newIt(obj);
                return (newIt -= nb);
            }            

			reference operator[](int nb) const
            {
                value_type* tmp(this->obj);

                movePtr(tmp, nb, 1);
                return (*tmp);
            }

			difference_type operator-(IteratorVector it) const
            {
                return (this->obj - it.obj);
            }

			IteratorVector operator++(int)
			{
				IteratorVector res(*this);
				++(*this);
				return (res);
			}

			IteratorVector operator--(int)
			{
				IteratorVector res(*this);
				--(*this);
				return (res);
			}

			IteratorVector &operator++()
			{
				++obj;
				return(*this);
			}

			IteratorVector &operator--()
			{
				--obj;
				return(*this);
			}

			bool operator!=(const IteratorVector &it)
			{
				if (obj != it.obj)
					return(true);
				return(false);
			}

			bool operator==(const IteratorVector &it)
			{
				if (obj == it.obj)
					return(true);
				return(false);
			}

			bool operator<(const IteratorVector& it) const     { return (it.obj > this->obj); }
            bool operator>(const IteratorVector& it) const     { return (it.obj < this->obj); }
            bool operator<=(const IteratorVector& it) const    { return (it.obj >= this->obj); }
            bool operator>=(const IteratorVector& it) const    { return (it.obj <= this->obj); }

			T& operator*()
			{
				return(*obj);
			}

			T* operator&()
			{
				return(obj);
			}

			operator ConstIteratorVector<T>()
			{
				return (ConstIteratorVector<T>(obj));
			}
			
			bool operator!=(const ConstIteratorVector<T>& it) const
			{
				if (obj != it.get_data())
					return(true);
				return(false);
			}

			bool operator==(const ConstIteratorVector<T>& it) const
			{
				if (obj == it.get_data())
					return(true);
				return(false);
			}

			bool operator<(const ConstIteratorVector<T>& it) const     { return (it.get_data() > this->obj); }
            bool operator>(const ConstIteratorVector<T>& it) const     { return (it.get_data() < this->obj); }
            bool operator<=(const ConstIteratorVector<T>& it) const    { return (it.get_data() >= this->obj); }
            bool operator>=(const ConstIteratorVector<T>& it) const    { return (it.get_data() <= this->obj); }

			T* get_data() const
			{
				return (obj);
			}
			
			private:
				void movePtr(T*& val, long nb, bool sign) const
				{
					int mov;

					if (sign == 1)
						mov = nb > 0 ? mov = 1: mov = -1;
					else
						mov = nb > 0 ? mov = -1: mov = 1;

					if (nb < 0)
						nb *= -1;
					for (; nb > 0; --nb)
						val += mov;
				}
	};

	template<typename T>
	class ConstIteratorVector
	{
		public:
			typedef std::random_access_iterator_tag                 iterator_category;
			typedef long int                                        difference_type;
			typedef T                                               value_type;
			typedef size_t                                          size_type;		
			typedef T*                                              pointer;
			typedef T&												reference;
			// typedef typename IteratorVector<T>						IteratorVector;
		private:
			T* obj;
		public:
			ConstIteratorVector()
			{
				obj = NULL;
			}

			ConstIteratorVector(T* first)
			{
				obj = first;
			}

			~ConstIteratorVector()
			{
			}

			ConstIteratorVector& operator=(const ConstIteratorVector& it)
            {
                if (this != &it)
                    obj = it.obj;
                return (*this);
            }
			

			
			ConstIteratorVector& operator+=(int nb)
            {
                movePtr(this->obj, nb, 1);
                return (*this);
            }

			ConstIteratorVector& operator-=(int nb)
            {
                movePtr(this->obj, nb, 0);
                return (*this);
            }


			ConstIteratorVector operator+(int nb) const
            {
                ConstIteratorVector it(*this);
                
                movePtr(it.obj, nb, 1);
                return (it);
            }
			
			friend ConstIteratorVector operator+(int nb, const ConstIteratorVector& obj)
            {
            	ConstIteratorVector newIt(obj);
            	return (newIt += nb);
            }

			ConstIteratorVector operator-(int nb) const
            {
                ConstIteratorVector it(*this);
                
                movePtr(it.obj, nb, 0);
                return (it);
            }

            friend ConstIteratorVector operator-(int nb, const ConstIteratorVector& obj)
            {
                ConstIteratorVector newIt(obj);
                return (newIt -= nb);
            }            

			reference operator[](int nb) const
            {
                value_type* tmp(this->obj);

                movePtr(tmp, nb, 1);
                return (*tmp);
            }

			difference_type operator-(ConstIteratorVector it) const
            {
                return (this->obj - it.obj);
            }

			difference_type operator-(ConstIteratorVector i)
			{
				size_t a;
				a = obj - i.obj;
				return (obj - i.obj);
			}
			
			difference_type operator+(ConstIteratorVector i)
			{
				return (obj + i.obj);
			}

			// size_t operator+(IteratorVector i, size_t k)
			// {
				
			// 	return (obj + i.obj);
			// }

			ConstIteratorVector &operator++(int)
			{
				ConstIteratorVector res(*this);
				++(*this);
				return (res);
			}

			ConstIteratorVector &operator--(int)
			{
				ConstIteratorVector res(*this);
				--(*this);
				return (res);
			}

			ConstIteratorVector &operator++()
			{
				++obj;
				return (*this);
			}

			ConstIteratorVector &operator--()
			{
				--obj;
				return(*this);
			}

			bool operator!=(const ConstIteratorVector &it)
			{
				return (obj != it.obj);
					// return(true);
				// return(false);
			}

			bool operator==(const ConstIteratorVector &it)
			{
				if (obj == it.obj)
					return(true);
				return(false);
			}

			bool operator<(const ConstIteratorVector<T>& it) const     { return (it.obj > this->obj); }
            bool operator>(const ConstIteratorVector<T>& it) const     { return (it.obj < this->obj); }
            bool operator<=(const ConstIteratorVector<T>& it) const    { return (it.obj >= this->obj); }
            bool operator>=(const ConstIteratorVector<T>& it) const    { return (it.obj <= this->obj); }

			bool operator!=(const IteratorVector<T> &it)
			{
				return (obj != it.get_data());
					// return(true);
				// return(false);
			}

			bool operator==(const IteratorVector<T> &it)
			{
				if (obj == it.get_data())
					return(true);
				return(false);
			}

			bool operator<(const IteratorVector<T>& it) const     { return (it.get_data() > this->obj); }
            bool operator>(const IteratorVector<T>& it) const     { return (it.get_data() < this->obj); }
            bool operator<=(const IteratorVector<T>& it) const    { return (it.get_data() >= this->obj); }
            bool operator>=(const IteratorVector<T>& it) const    { return (it.get_data() <= this->obj); }

			T& operator*()
			{
				return(*obj);
			}

			T* operator&() 
			{
				return(obj);
			}

			T* get_data() const
			{
				return (obj);
			}

		private:
			void movePtr(T*& val, long nb, bool sign) const
			{
				int mov;

				// If addtion, mov will be positive. If substraction, negative.
				if (sign == 1)
					mov = nb > 0 ? mov = 1: mov = -1;
				else
					mov = nb > 0 ? mov = -1: mov = 1;

				if (nb < 0)
					nb *= -1;
				for (; nb > 0; --nb)
					val += mov;
			}
	};
}

#endif