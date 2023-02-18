import 'package:calci/widgets/calc_button.dart';
import 'package:flutter/material.dart';

class CalcKeyboardLayout extends StatelessWidget {
  const CalcKeyboardLayout({super.key});

  @override
  Widget build(BuildContext context) {
    final List<String> buttonText = [
      'C',
      '%',
      'AC',
      '/',
      '7',
      '8',
      '9',
      '*',
      '4',
      '5',
      '6',
      '-',
      '1',
      '2',
      '3',
      '+',
      '00',
      '0',
      '.',
      '='
    ];
    return GridView.builder(
      physics: const NeverScrollableScrollPhysics(),
      gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
        crossAxisCount: 4,
        mainAxisSpacing: 5.0,
        crossAxisSpacing: 5.0,
      ),
      itemCount: buttonText.length,
      itemBuilder: (context, index) {
        return CalcButton(
          fontSize: fontSize(buttonText[index]) ? 25 : 20,
          onTap: () {},
          bottonText: buttonText[index],
        );
      },
    );
  }

  bool fontSize(String x) {
    if (x == 'C' ||
        x == '%' ||
        x == 'AC' ||
        x == '/' ||
        x == '*' ||
        x == '+' ||
        x == '-' ||
        x == '+' ||
        x == '=' ||
        x == '.') {
      return true;
    }
    return false;
  }
}
