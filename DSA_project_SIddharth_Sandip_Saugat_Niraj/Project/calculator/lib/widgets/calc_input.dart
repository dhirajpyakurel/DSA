import 'package:calci/providers/calc_provider.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

class CalcInput extends StatelessWidget {
  const CalcInput({
    super.key,
    required this.controller,
  });

  final TextEditingController controller;

  @override
  Widget build(BuildContext context) {
    final calcProvider = Provider.of<CalcProvider>(context);
    return Column(
      crossAxisAlignment: CrossAxisAlignment.end,
      children: [
        Container(
          padding: const EdgeInsets.all(20.0),
          child: TextFormField(
            controller: calcProvider.calcController,
            style: TextStyle(color: Colors.grey[600], fontSize: 20),
            enabled: false,
            decoration: const InputDecoration(
              border: OutlineInputBorder(),
            ),
          ),
        ),
        Padding(
          padding: const EdgeInsets.only(right: 20.0),
          child: Text(
            calcProvider.result.toString(),
            style: TextStyle(fontSize: 20, color: Colors.grey[500]),
          ),
        ),
      ],
    );
  }
}
