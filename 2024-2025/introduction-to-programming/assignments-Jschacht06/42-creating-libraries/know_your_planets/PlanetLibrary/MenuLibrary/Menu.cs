namespace MenuLibrary
{
    public class Menu
    {
        private List<string> menuItems;
        private int selectedIndex;

        public Menu(List<string> items)
        {
            menuItems = new List<string>(items);
            selectedIndex = 0;
        }

        public override string ToString()
        {
            string menuDisplay = "";
            for (int i = 0; i < menuItems.Count; i++)
            {
                if (i == selectedIndex)
                {
                    menuDisplay += "> " + menuItems[i] + " <" + Environment.NewLine;
                }
                else
                {
                    menuDisplay += "  " + menuItems[i] + Environment.NewLine;
                }
            }
            return menuDisplay;
        }

        public string GetSelectedMenuChoice()
        {
            return menuItems[selectedIndex];
        }

        public void MoveUp()
        {
            if (selectedIndex > 0)
                selectedIndex--;
        }

        public void MoveDown()
        {
            if (selectedIndex < menuItems.Count - 1)
                selectedIndex++;
        }

        public void AddMenuItem(string item)
        {
            menuItems.Add(item);
        }
    }
}