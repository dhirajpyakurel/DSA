import 'package:calci/providers/calc_provider.dart';
import 'package:calci/screens/splash_screen.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider<CalcProvider>(
      create: (context) {
        return CalcProvider();
      },
      builder: (context, child) {
        return const MaterialApp(
          debugShowCheckedModeBanner: false,
          title: 'Calculator',
          home: SplashScreen(),
        );
      },
    );
  }
}
