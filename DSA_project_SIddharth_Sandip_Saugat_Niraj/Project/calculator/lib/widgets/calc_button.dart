import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../providers/calc_provider.dart';

class CalcButton extends StatefulWidget {
  final Function() onTap;
  const CalcButton({
    super.key,
    required this.onTap,
    required this.bottonText,
    required this.fontSize,
  });
  final String bottonText;
  final double fontSize;

  @override
  State<CalcButton> createState() => _CalcButtonState();
}

class _CalcButtonState extends State<CalcButton> {
  bool isButtonPressed = false;
  @override
  Widget build(BuildContext context) {
    final calcProvider = Provider.of<CalcProvider>(context);

    return Padding(
      padding: const EdgeInsets.all(5.0),
      child: GestureDetector(
        onTap: () {
          calcProvider.onPressedButton(widget.bottonText);
          setState(() {
            isButtonPressed = true;
          });
          Future.delayed(
            const Duration(milliseconds: 180),
            () {
              setState(() {
                isButtonPressed = false;
              });
            },
          );
        },
        child: AnimatedContainer(
          duration: const Duration(milliseconds: 200),
          height: 20,
          width: 20,
          decoration: BoxDecoration(
            color: Colors.grey[300],
            borderRadius: BorderRadius.circular(12),
            border: Border.all(
                color: isButtonPressed
                    ? Colors.grey.shade200
                    : Colors.grey.shade300),
            boxShadow: isButtonPressed
                ? [
                    //no shadow
                  ]
                : [
                    //darker shadow on bottom right
                    BoxShadow(
                      color: Colors.grey.shade500,
                      offset: const Offset(6, 6),
                      blurRadius: 15,
                      spreadRadius: 1,
                    ),
                    //lighter shadow on top left
                    const BoxShadow(
                      color: Colors.white,
                      offset: Offset(-6, -6),
                      blurRadius: 15,
                      spreadRadius: 1,
                    ),
                  ],
          ),
          child: Center(
              child: Text(
            "${widget.bottonText}",
            style: TextStyle(
                fontSize: widget.fontSize,
                fontWeight: FontWeight.bold,
                color: Colors.grey[500]),
          )),
        ),
      ),
    );
  }
}
