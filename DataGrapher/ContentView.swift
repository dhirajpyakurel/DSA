//
//  ContentView.swift
//  DataGrapher
//
//  Created by Djerry on 18/02/2023.
//


import SwiftUI

struct ContentView: View {
    @State private var newItemName = ""
    @State private var newItemPrice = ""
    @State private var items: [Item] = []
    @State private var showingGraphV = false
    
    var body: some View {
        NavigationView{
            Form{
                Section (header: Text ("Data Entry"))
                {
                    TextField("Enter item name", text: $newItemName)
                    TextField("Enter price", text: $newItemPrice)
                        .keyboardType(.decimalPad)
                }
                Section (header: Text ("Shopping List"))
                {
                    if !items.isEmpty {
                        List {
                            ForEach(items) { item in
                                Text("\(item.name) - Rs. \(item.price)")
                            }
                            .onDelete(perform: removeItems)
                            .padding()
                        }
                        HStack{
                            Spacer()
                            Button(action: {
                                self.showingGraphV.toggle()
                            }) {
                                Text("Show Graph")
                                    .padding(.horizontal, 20)
                                    .padding(.vertical, 10)
                                    .background(Color.cyan)
                                    .foregroundColor(.white)
                                    .cornerRadius(10)
                            }
                            Spacer()
                        }
                       
                        .sheet (isPresented: $showingGraphV) {
                            GraphView(items: items)
                        }
                        
                        .padding()
                    }
                }
                
            }
            .navigationTitle("Home")
            .toolbar {
                ToolbarItemGroup (placement: .navigationBarTrailing) {
                    Button("Save", action: {
                        if let price = Int(newItemPrice) {
                            let newItem = Item(price: price, name: newItemName)
                            items.append(newItem)
                            newItemName = ""
                            newItemPrice = ""
                        }
                    })
                    .accentColor (.green)
                    .font(.system(size: 24))
                }
                /*  VStack{
                 Button(action: , label: {
                 Text("Add")
                 .padding(.horizontal, 20)
                 .padding(.vertical, 10)
                 .background(Color.green)
                 .foregroundColor(.white)
                 .cornerRadius(10)
                 })
                 
                 */
                 }
                
            }
            
            
        }
        func removeItems(at offsets: IndexSet)
        {
            items.remove(atOffsets: offsets)
        }
    }
    
    struct ContentView_Previews: PreviewProvider {
        static var previews: some View {
            ContentView()
        }
    }
