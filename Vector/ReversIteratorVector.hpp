#ifndef REVERSITERATORVECTOR_HPP
#define REVERSITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>
#include "IteratorVector.hpp"

namespace ft
{
	template<typename T>
	class IteratorVector;

	template<typename T>
	class ConstIteratorVector;

	template<typename T>
	class ConstReversIteratorVector;

	template<typename T>
	class ReversIteratorVector
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
			ReversIteratorVector()
			{
				obj = NULL;
			}

			ReversIteratorVector(T* first)
			{
				obj = first;
			}

			~ReversIteratorVector()
			{
			}

			ReversIteratorVector(const IteratorVector<T>& it)
			{
				obj = it.get_data();
			}

			ReversIteratorVector& operator=(const ReversIteratorVector& it)
			{
				if (this != &it)
					obj = it.obj;
				return (*this);
			}
				
			ReversIteratorVector& base()
			{
				return (*this);
			}

			ReversIteratorVector& operator+=(int nb)
			{
				movePtr(this->obj, nb, 1);
				return (*this);
			}

			ReversIteratorVector& operator-=(int nb)
			{
				movePtr(this->obj, nb, 0);
				return (*this);
			}


			ReversIteratorVector operator+(int nb) const
			{
				ReversIteratorVector it(*this);
				
				movePtr(it.obj, nb, 1);
				return (it);
			}

			friend ReversIteratorVector operator+(int nb, const ReversIteratorVector& obj)
			{
				ReversIteratorVector newIt(obj);
				return (newIt += nb);
			}

			ReversIteratorVector operator-(int nb) const
			{
				ReversIteratorVector it(*this);
				
				movePtr(it.obj, nb, 0);
				return (it);
			}

		    friend ReversIteratorVector operator-(int nb, const ReversIteratorVector& obj)
		    {
		        ReversIteratorVector newIt(obj);
		        return (newIt -= nb);
		    }            


			reference operator[](int nb) const
			{
				value_type* tmp(this->obj);

				movePtr(tmp, nb, 1);
				return (*tmp);
			}
			
			difference_type operator-(ReversIteratorVector it) const
			{
				return (this->obj - it.obj);
			}

			ReversIteratorVector operator++(int)
			{
				ReversIteratorVector res(*this);
				++(*this);
				return (res);
			}

			ReversIteratorVector operator--(int)
			{
				ReversIteratorVector res(*this);
				--(*this);
				return (res);
			}

			ReversIteratorVector &operator++()
			{
				++obj;
				return(*this);
			}

			ReversIteratorVector &operator--()
			{
				--obj;
				return(*this);
			}

			operator IteratorVector<T>()
			{
				return (IteratorVector<T>(obj));
			}
			
			operator ConstReversIteratorVector<T>()
			{
				return (ConstReversIteratorVector<T>(obj));
			}
			
			bool operator!=(const ReversIteratorVector &it)
			{
				if (obj != it.obj)
					return(true);
				return(false);
			}

			bool operator==(const ReversIteratorVector &it)
			{
				if (obj == it.obj)
					return(true);
				return(false);
			}

			bool operator<(const ReversIteratorVector& it) const     { return (it.obj > this->obj); }
			bool operator>(const ReversIteratorVector& it) const     { return (it.obj < this->obj); }
			bool operator<=(const ReversIteratorVector& it) const    { return (it.obj >= this->obj); }
			bool operator>=(const ReversIteratorVector& it) const    { return (it.obj <= this->obj); }

			bool operator!=(const IteratorVector<T> &it)
			{
				if (obj != it.get_data())
					return(true);
				return(false);
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

			bool operator!=(const ConstReversIteratorVector<T> &it)
			{
				if (obj != it.get_data())
					return(true);
				return(false);
			}

			bool operator==(const ConstReversIteratorVector<T> &it)
			{
				if (obj == it.get_data())
					return(true);
				return(false);
			}

			bool operator<(const ConstReversIteratorVector<T>& it) const     { return (it.get_data() > this->obj); }
			bool operator>(const ConstReversIteratorVector<T>& it) const     { return (it.get_data() < this->obj); }
			bool operator<=(const ConstReversIteratorVector<T>& it) const    { return (it.get_data() >= this->obj); }
			bool operator>=(const ConstReversIteratorVector<T>& it) const    { return (it.get_data() <= this->obj); }

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
	class ConstReversIteratorVector
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
			ConstReversIteratorVector()
			{
				obj = NULL;
			}

			ConstReversIteratorVector(T* first)
			{
				obj = first;
			}

			~ConstReversIteratorVector()
			{
			}
			
			ConstReversIteratorVector(const IteratorVector<T>& it)
			{
				obj = it.get_data();
			}
			
			ConstReversIteratorVector(const ConstIteratorVector<T>& it)
			{
				obj = it.get_data();
			}

			ConstReversIteratorVector(const ReversIteratorVector<T>& it)
			{
				obj = it.get_data();
			}

			ConstReversIteratorVector& operator=(const ConstReversIteratorVector& it)
			{
				if (this != &it)
					obj = it.obj;
				return (*this);
			}
				
			ConstReversIteratorVector& base()
			{
				return (*this);
			}

			ConstReversIteratorVector& operator+=(int nb)
			{
				movePtr(this->obj, nb, 1);
				return (*this);
			}

			ConstReversIteratorVector& operator-=(int nb)
			{
				movePtr(this->obj, nb, 0);
				return (*this);
			}


			ConstReversIteratorVector operator+(int nb) const
			{
				ConstReversIteratorVector it(*this);
				
				movePtr(it.obj, nb, 1);
				return (it);
			}

			friend ConstReversIteratorVector operator+(int nb, const ConstReversIteratorVector& obj)
			{
				ConstReversIteratorVector newIt(obj);
				return (newIt += nb);
			}

			ConstReversIteratorVector operator-(int nb) const
			{
				ConstReversIteratorVector it(*this);
				
				movePtr(it.obj, nb, 0);
				return (it);
			}

		    friend ConstReversIteratorVector operator-(int nb, const ConstReversIteratorVector& obj)
		    {
		        ConstReversIteratorVector newIt(obj);
		        return (newIt -= nb);
		    }            

			reference operator[](int nb) const
			{
				value_type* tmp(this->obj);

				movePtr(tmp, nb, 1);
				return (*tmp);
			}
			
			difference_type operator-(ConstReversIteratorVector it) const
			{
				return (this->obj - it.obj);
			}

			ConstReversIteratorVector operator++(int)
			{
				ConstReversIteratorVector res(*this);
				++(*this);
				return (res);
			}

			ConstReversIteratorVector operator--(int)
			{
				ConstReversIteratorVector res(*this);
				--(*this);
				return (res);
			}

			ConstReversIteratorVector &operator++()
			{
				++obj;
				return(*this);
			}

			ConstReversIteratorVector &operator--()
			{
				--obj;
				return(*this);
			}

			operator IteratorVector<T>()
			{
				return (IteratorVector<T>(obj));
			}

			operator ConstIteratorVector<T>()
			{
				return (ConstIteratorVector<T>(obj));
			}
			
			operator ReversIteratorVector<T>()
			{
				return (ReversIteratorVector<T>(obj));
			}

			bool operator!=(const ConstReversIteratorVector &it)
			{
				if (obj != it.obj)
					return(true);
				return(false);
			}

			bool operator==(const ConstReversIteratorVector &it)
			{
				if (obj == it.obj)
					return(true);
				return(false);
			}

			bool operator<(const ConstReversIteratorVector& it) const     { return (it.obj > this->obj); }
			bool operator>(const ConstReversIteratorVector& it) const     { return (it.obj < this->obj); }
			bool operator<=(const ConstReversIteratorVector& it) const    { return (it.obj >= this->obj); }
			bool operator>=(const ConstReversIteratorVector& it) const    { return (it.obj <= this->obj); }

			
			bool operator!=(const ReversIteratorVector<T> &it)
			{
				if (obj != it.get_data())
					return(true);
				return(false);
			}

			bool operator==(const ReversIteratorVector<T> &it)
			{
				if (obj == it.get_data())
					return(true);
				return(false);
			}

			bool operator<(const ReversIteratorVector<T>& it) const     { return (it.get_data() > this->obj); }
			bool operator>(const ReversIteratorVector<T>& it) const     { return (it.get_data() < this->obj); }
			bool operator<=(const ReversIteratorVector<T>& it) const    { return (it.get_data() >= this->obj); }
			bool operator>=(const ReversIteratorVector<T>& it) const    { return (it.get_data() <= this->obj); }

			bool operator!=(const IteratorVector<T> &it)
			{
				if (obj != it.get_data())
					return(true);
				return(false);
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

			T &operator*()
			{
				return(*obj);
			}

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
}
#endif









			// 	bool operator<(const IteratorVector& it) const     { return (it.obj > this->obj); }
			//     bool operator>(const IteratorVector& it) const     { return (it.obj < this->obj); }
			//     bool operator<=(const IteratorVector& it) const    { return (it.obj >= this->obj); }
			//     bool operator>=(const IteratorVector& it) const    { return (it.obj <= this->obj); }

			// 	T& operator*()
			// 	{
			// 		return(*obj);
			// 	}

			// 	T* operator&()
			// 	{
			// 		return(obj);
			// 	}

			// 	operator ConstIteratorVector<T>()
			// 	{
			// 		return (ConstIteratorVector<T>(obj));
			// 	}
				
			// 	bool operator!=(const ConstIteratorVector<T>& it) const
			// 	{
			// 		if (obj != it.get_data())
			// 			return(true);
			// 		return(false);
			// 	}

			// 	bool operator==(const ConstIteratorVector<T>& it) const
			// 	{
			// 		if (obj == it.get_data())
			// 			return(true);
			// 		return(false);
			// 	}

			// 	bool operator<(const ConstIteratorVector<T>& it) const     { return (it.get_data() > this->obj); }
			//     bool operator>(const ConstIteratorVector<T>& it) const     { return (it.get_data() < this->obj); }
			//     bool operator<=(const ConstIteratorVector<T>& it) const    { return (it.get_data() >= this->obj); }
			//     bool operator>=(const ConstIteratorVector<T>& it) const    { return (it.get_data() <= this->obj); }

			// 	T* get_data() const
			// 	{
			// 		return (obj);
			// 	}
				
			// 	private:
			// 		void movePtr(T*& val, long nb, bool sign) const
			// 		{
			// 			int mov;

			// 			if (sign == 1)
			// 				mov = nb > 0 ? mov = 1: mov = -1;
			// 			else
			// 				mov = nb > 0 ? mov = -1: mov = 1;

			// 			if (nb < 0)
			// 				nb *= -1;
			// 			for (; nb > 0; --nb)
			// 				val += mov;
			// 		}
