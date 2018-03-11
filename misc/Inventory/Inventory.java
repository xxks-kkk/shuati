// Code Review - Inventory
class Inventory{
    public List<Item> items; // in our current game design, each item is either a quest from iterm or a normal item
    public List<Item> questItems; // for convenience, a subset of items, containing only quest items
    public List<Item> normalItems; // for convenience, a subset of items, containing only normal items

    // the user interface will display the last item we picked up
    private Item lastItemCollected;

    public Item LastItemCollected() {
        return lastItemCollected;
    }

    public void getitem(Item i, int quantity){
        for(int x = 0; x < quantity; ++x){
            items.Add(i);
            if (i.IsQuestItem()){
                questItems.Add(i);
            } else {
                normalItems.Add(i);
            }
        }

        AchievementSystem.instance.DidModifyItem("gain", i.identifier, quantity);
        didpickupitem(i);
    }

    public void loseitem(Item i, int quantity){
        for(int x = 0; x < quantity; ++x){
            items.Remove(i);
            if (i.IsQuestItem()){
                questItems.Remove(i);
            } else {
                normalItems.Remove(i);
            }
        }
        AchievementSystem.instance.DidModifyItem("lose", i.identifier, quantity);
    }

    public void didpickupitem(Item i){
        lastItemCollected = i;
    }
}