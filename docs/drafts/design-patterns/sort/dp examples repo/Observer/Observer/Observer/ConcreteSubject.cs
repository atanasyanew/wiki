namespace Observer
{
    using System;
    using System.Collections.Generic;
    using System.Text;

    /// <summary>
    /// The 'ConcreteSubject' class
    /// </summary>
    class ConcreteSubject : Subject
    {
        private string subjectState;

        // Gets or sets subject state
        public string SubjectState { get; set; }
    }
}
