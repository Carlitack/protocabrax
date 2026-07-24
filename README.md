<div align="center">
  <img src="images/protopirate_10px.png" alt="Icon" width="80" />
  <h1>ProtoPirate</h1>
  <p><strong>Toolkit d'analyse de rolling codes Sub-GHz pour Flipper Zero</strong></p>
  <p>
    <a href="https://github.com/Carlitack/protocabrax/actions">
      <img src="https://github.com/Carlitack/protocabrax/actions/workflows/build.yml/badge.svg" alt="Build">
    </a>
    <a href="https://joelewis012.github.io/flipper-fap-actions/">
      <img src="https://img.shields.io/badge/FlipperFAP-Ready-FF4400" alt="FlipperFAP">
    </a>
    <img src="https://img.shields.io/badge/Flipper_Zero-FAP-blue" alt="Flipper Zero">
  </p>
  <p>
    <strong>Fork amélioré par <a href="https://github.com/Carlitack">Carlitack</a></strong> —
    <a href="#-protocoles-supportés">Protocoles</a> •
    <a href="#-ameliorations">Améliorations</a> •
    <a href="#-compilation">Compilation</a>
  </p>
</div>

---

**ProtoPirate** est un toolkit expérimental d'analyse et de décodage de rolling
codes pour Flipper Zero, développé par **The Pirates' Plunder**.

> ⚠️ **Réception seule par défaut** – L'émission est désactivée par défaut
> pour éviter toute désynchronisation accidentelle. Active-la dans **Settings**.

## 🚗 Protocoles supportés

### AM
Chrysler V0, Fiat V0/V1/V2, Ford V0/V3, Honda V1, Kia V1/V2, Mazda V0,
Porsche Touareg, PSA (Peugeot/Citroën), Renault V0, StarLine, Subaru, VAG

### FM
Ford V1/V2/V3, Honda Static/V1/V2, Kia V0/V2/V3-V4/V5/V6/V7, Mazda V0,
Mitsubishi V0, PSA, Scher-Khan

## ✨ Améliorations (vs original)

| Feature | Statut |
|---|---|
| Timing Tuner débloqué | ✅ |
| Logging réparé (erreurs visibles) | ✅ |
| Dead code nettoyé | ✅ |
| AUT64 validations + pack activés | ✅ |
| KeeLoq Secure (type 3) + FAAC (type 5) | ✅ Ajoutés |
| TX activé par défaut | ✅ |
| StarLine TODOs fixés | ✅ |
| CI GitHub Actions (4 cibles) | ✅ |
| Tests KeeLoq 14/14 + AUT64 16/20 | ✅ |

## 🔧 Compilation

**FlipperFAP** → `https://github.com/Carlitack/protocabrax`

**GitHub Actions** → Push sur main, artifacts dans l'onglet Actions

**Local** → `pip install ufbt && ufbt`

## 📝 Licence

GPLv3 — original par **The Pirates' Plunder**
