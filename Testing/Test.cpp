#include "Test.hpp"

// void push(Key a, Node_or_leaf_map **t)
		// {
		//     if ((*t) == NULL)                   //Если дерева не существует
		//     {
		//         (*t) = new Node_or_leaf_map;                //Выделяем память
		//         (*t)->info = a;                 //Кладем в выделенное место аргумент a
		//         (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
		//         return;                         //Заложили семечко, выходим
		//     }
		//        //Дерево есть
		//         if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
		//         else push(a, &(*t)->l);         //Иначе кладем его влево
		// }
		
		// /*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
		// void print (Node_or_leaf_map *t, Key u)
		// {
		//     if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
		//     else //Иначе
		//     {
		//         print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
		//         for (int i=0; i<u; ++i) std::cout << "|";
		//         std::cout << t->info << std::endl;            //И показываем элемент
		//         u--;
		//     }
		//     print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
		// }
// 		func inorderTraversal(x : Node):
//    			if (x != null)
//       			inorderTraversal(x.left)
//       			print x.key
//       			inorderTraversal(x.right)