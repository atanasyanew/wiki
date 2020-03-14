namespace Observer_stock_changes_example
{
    using System;

    class Investor : IInvestor
    {
        private string name;

        public Investor(string name)
        {
            this.name = name;
        }

        public void Update(Stock stock)
        {
            Console.WriteLine("Notified {0} of {1}'s " +  "change to {2:C}", name, stock.Symbol, stock.Price);
        }

        public Stock Stock { get; set; }
    }
}
