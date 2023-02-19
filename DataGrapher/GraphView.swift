//
//  GraphView.swift
//  DataGrapher
//
//  Created by Djerry on 18/02/2023.
//
import SwiftUI
struct GraphView: View {
    @Environment (\.presentationMode) var presentationMode:Binding<PresentationMode>
    var items: [Item]
    @State private var isSorted = false
  
    var sortedItems: [Item] {
        var sortedItems = items
        for i in 0..<sortedItems.count {
            for j in 1..<sortedItems.count - i {
                if sortedItems[j].price < sortedItems[j - 1].price {
                    let temp = sortedItems[j]
                    sortedItems[j] = sortedItems[j - 1]
                    sortedItems[j - 1] = temp
                }
            }
        }
        return sortedItems
    }
    
    var totalPrice: Int {
        items.map { $0.price }.reduce(0,+)
    }
    var body: some View {
        
        
        NavigationStack{
                VStack{
                    VStack(alignment: .leading, spacing: 12){
                        HStack{
                            Text("BarGraph")
                                .font(.system(size: 22))
                                .fontWeight(.bold)
                                Spacer()
                            Text("Total Expenditure: \(totalPrice)")
                                .padding(.top,60)
                                .fontWeight(.bold)
                            
                        }
                        
                        displayGraph(items: isSorted ? sortedItems : items)
                    

                    }
                    .padding()
                    .background{RoundedRectangle (cornerRadius: 10, style: .continuous)
                        .fill(.white.shadow(.drop(radius: 2)))}
                
                    HStack{
                        Button(action: {
                            isSorted = true
                        }, label: {
                            Text("Sort")
                                .padding(.horizontal, 20)
                                .padding(.vertical, 10)
                                .background(Color.green)
                                .foregroundColor(.white)
                                .fontWeight(.semibold)
                                .cornerRadius(10)
                        }).padding()
                        Spacer()
                        Button (action: {
                            self.presentationMode.wrappedValue.dismiss()
                        }){
                            Text("Home")
                                .padding(.horizontal, 20)
                                .padding(.vertical, 10)
                                .background(Color.cyan)
                                .foregroundColor(.white)
                                .fontWeight(.semibold)
                                .cornerRadius(10)

                        }
                    }.frame(width: 340)
                }
                    .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .top)
                    .navigationTitle("Graphs")
                    .padding(10)
                    
            }
    }
    @ViewBuilder
    func displayGraph(items: [Item]) -> some View {
        
        ZStack{
            HStack(alignment: .lastTextBaseline) {

                ForEach(items) { item in
                    let NPrice = Swift.min(item.price/15,260)

                    VStack {
                        Text("\(item.price)")
                            .font(.caption)
                            .foregroundColor(Color.black)
                            //ZStack {
                            Rectangle()
                                .foregroundColor(color(item.price))
                                .frame(width: 35, height: CGFloat(NPrice), alignment: .bottom)
                                .cornerRadius(6)
                               // .foregroundColor(.white)
                     //   }
                        Text(item.name)
                    }
                }
            }
            .padding(10)
            .cornerRadius(16)
            .frame(width: 340, height: 400, alignment: .bottom)
           // .background("barchart")
        }
    }
    func color(_ temp:Int)->Color{
        if (temp <= 200){
            return .green
        }
        else if(temp <= 500)
        {
            return .mint
        }
        else if(temp <= 1000)
        {
            return .yellow
        }
        else if(temp <= 5000)
        {
            return .orange
        }
        else{
            return .red
        }
    }

}

struct GraphView_Previews: PreviewProvider {
    static var previews: some View {
        let items = [
            Item(price: 102, name: "a"),
            Item(price: 300, name: "b"),
           
            Item(price: 1223, name: "c"),
                   Item(price: 600, name: "e"),
                   Item(price: 5500, name: "g"),
                  
                   Item(price: 2400, name: "f")
               ]
        GraphView(items: items)
    }
}
