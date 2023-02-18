import 'dart:async';

import 'package:calci/screens/home_screen.dart';
import 'package:flutter/material.dart';

class SplashServices {
  void splash(BuildContext context) {
    Timer(
      const Duration(seconds: 3),
      () => Navigator.push(
        context,
        MaterialPageRoute(
          builder: (context) => const HomeScreen(),
        ),
      ),
    );
  }
}
