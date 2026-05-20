using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using The_Company_Relationship.The_Company_Relationship;

namespace The_Company_Relationship
{
    public class SwipeCard
    {
        //attributes
        private int cardId;
        private string cardNumber;
        private Manager assignedManager;
        //properties
        public int CardId
        {
            get { return cardId; }
            set { cardId = value; }
        }
        public string CardNumber
        {
            get { return cardNumber; }
            set { cardNumber = value; }
        }
        public Manager AssignedManager
        {
            get { return assignedManager; }
            set { assignedManager = value; }
        }
        //constructor
        public SwipeCard(int cardId, string cardNumber, Manager assignedManager)
        {
            CardId = cardId;
            CardNumber = cardNumber;
            AssignedManager = assignedManager;
        }
        //methods
        public void AssignManager(Manager manager)
        {
            AssignedManager = manager;
        }


    }
}
