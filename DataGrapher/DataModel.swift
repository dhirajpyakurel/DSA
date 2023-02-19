//
//  DataModel.swift
//  DataGrapher
//
//  Created by Djerry on 18/02/2023.
//
import Foundation
struct Item: Identifiable {
    let id = UUID()
    let price: Int
    let name: String
}
