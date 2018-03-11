Comment:

1. Coding Style. Usually, we want to add the comment section to each function about what's the purpose of the function, what's the precondition and postcondition that this function expects and delivers. In-line comment for "items", "questItems", "normalItems" may not be ideal.

2. Overall, the array list organization for "items", "questItems ", " normalItems" may not be efficient. We can use the HashMap to organize the data like following:


// in our current game design, each item is either a quest from iterm or a normal item
public HashMap<Item, Integer> items;
// for convenience, a subset of items, containing only quest items
public HashMap<Item, Integer> questItems;
// for convenience, a subset of items, containing only normal items
public HashMap<Item, Integer> normalItems;
The advantage of using HashMap over the list is that we can have O(1) access time on average instead of O(n) in array list. 


3. If we use the HashMap data structure instead of the array list data structure to organize our "items", " questItems ", " normalItems" data. We need to modify the "getitem" and "loseitem" accordingly.  For example, for the "getitem" we can modify the function as follows:


/*
 * description about function here
 */
public void getItem(Item i, int quantity){
    items.put(i, quantity);
    if i.IsQuestItem(){
        questItems.put(i, quantity);
    } else {
        normalItems.put(i, quantity);
    }
}


One thing to note is that we slightly change the semantics of function. Originally, the function appends "Item" object for "quantity" number of times in "items" and we check whether i is quest item or normal item. However, since the input is a single Item object and we assume Item class has a variable indicating whether it is a questItem or a normalItem, then it is unnecessary to use loop to repeatedly that a single Item is normal item or a quest item.  Thus, we can put "quantity" number of questItems or put "quantity" number of normalItems.

One caveat to our modification is that the original function stores "quantity" number of "Item" objects. However, here, we just store one "Item" object and a numeric value (i.e., "quantity"). Thus, we need to modify the caller of "getitem" function if the caller expects that there are "quantity" number of "Item" objects stored. 

Furthermore, there are duplicate data storage problem. We store subsets of the "items" into "normalItems" and "questItems" separately. We can, in fact, either store "normalItems" and "questItems" separately using hash map and completely get rid of the "items" or we use "items" only and whenever we fetch "Item", we can check the attribute of the Item to determine whether it is a normal item or a quest item. Personally, I think former one is better because using hash map on "normalItems" and "questItems" give us very fast access time and whenever we need the whole items, we can consolidate all the keys of each hashmap together.

"loseItem" can be modified similarly as "getitem". However, both the function naming can be changed to "GetItem" and "LoseItem".

4. The organization of the functions needs to improve. For example, we may want to move "didpickupitem" to the very top of the class and place it together with "LastItemCollected" functions because both of the functions are accessors.

5. The organization of the variable can also be improved. There is an extra blank between public variables and the private variable.