import 'package:calci/providers/calc_provider.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

class HistoryList extends StatefulWidget {
  const HistoryList({super.key});

  @override
  State<HistoryList> createState() => _HistoryListState();
}

class _HistoryListState extends State<HistoryList> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'History',
          style: TextStyle(
            color: Colors.grey,
            fontWeight: FontWeight.bold,
          ),
        ),
        backgroundColor: Colors.grey[300],
        centerTitle: true,
        elevation: 0,
        actions: [
          Consumer<CalcProvider>(
            builder: (context, value, child) {
              return IconButton(
                onPressed: () {
                  setState(() {
                    value.inputDatas.length = 0;
                    value.resultDatas.length = 0;
                  });
                },
                icon: const Icon(
                  Icons.delete,
                  color: Colors.grey,
                ),
              );
            },
          ),
        ],
      ),
      body: Consumer<CalcProvider>(
        builder: (context, value, child) {
          return ListView.builder(
            itemCount: value.inputDatas.length,
            itemBuilder: (context, index) {
              return ListTile(
                title: Text(
                  value.inputDatas[index] + ' =',
                  style: TextStyle(fontSize: 23, color: Colors.grey[500]),
                ),
                subtitle: Text(
                  value.resultDatas[index],
                  style: TextStyle(
                    fontSize: 18,
                    color: Colors.grey[400],
                  ),
                ),
                trailing: IconButton(
                  onPressed: () {
                    setState(
                      () {
                        value.inputDatas.removeAt(index);
                        value.resultDatas.removeAt(index);
                      },
                    );
                  },
                  icon: const Icon(Icons.close),
                ),
              );
            },
          );
        },
      ),
    );
  }
}
