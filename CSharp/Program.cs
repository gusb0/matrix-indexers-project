using System;

class Matrix
{
    private int[,] data;
    private int rows, cols;

    public Matrix(int rows, int cols)
    {
        this.rows = rows;
        this.cols = cols;
        data = new int[rows, cols];
        Random rand = new Random();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i, j] = rand.Next(1, 10);
    }

    public double this[int row]
    {
        get
        {
            double sum = 0;
            for (int j = 0; j < cols; j++)
                sum += data[row, j] * data[row, j];
            return Math.Sqrt(sum / cols);
        }
    }

    public int TotalSum
    {
        get
        {
            int sum = 0;
            foreach (int val in data)
                sum += val;
            return sum;
        }
    }

    public void Print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                Console.Write(data[i, j] + "\t");
            Console.WriteLine();
        }
    }
}

class Program
{
    static void Main()
    {
        Matrix m = new Matrix(3, 4);
        m.Print();
        for (int i = 0; i < 3; i++)
            Console.WriteLine($"Рядок {i}: {m[i]:F2}");
        Console.WriteLine($"Сума всіх елементів: {m.TotalSum}");
    }
}
