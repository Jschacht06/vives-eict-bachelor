using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TeachTheTeacher
{
    public class Teacher
    {
        //attributes
        public string firstname;
        public string lastname;

        //methods
        public void SetFirstname(string firstname)
        {
            this.firstname = firstname;
        }
        public void SetLastname(string lastname)
        {
            this.lastname = lastname;
        }
        public string Fullname()
        {
            return firstname + " " + lastname;
        }
        public string Email()
        {
            return firstname.ToLower().Replace(" ", "") + "." + lastname.ToLower().Replace(" ", "") + "@vives.be";
        }
        public override string ToString()
        {
            return Fullname() + " <" + Email() + ">";
        }
    }
}
