public class ElectronicStoreSellingTester2 extends ElectronicStoreStockTester{
    public static void main(String[] args) {
        ElectronicStore store = createStore1();

        store.sellProducts();
        System.out.println(store.getName() + "'s Ending Stock Is:");
        store.printStock();
    }
}
